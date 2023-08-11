#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define DEC(i, a, b) for(int i = a; i >= b; --i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define SZ(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;
const int mod = 1000000007;

int n, a[200010], b[200010], c[200010 << 2], ans[100010];
set<pii> mp;

void build(int p, int l, int r){
    if(l == r){
        c[p] = b[l];
        return;
    }
    int mid = getmid(l, r);
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    c[p] = min(c[p << 1], c[p << 1|1]);
}

int query(int p, int a, int b, int l, int r){
    if(a > b) return 1e9 + 1;
    if(a <= l && r <= b){
        return c[p];
    }
    int mid = getmid(l, r);
    int ans = 1e9 + 1;
    if(a <= mid) ans = min(ans, query(p << 1, a, b, l, mid));
    if(b > mid)  ans = min(ans, query(p << 1|1, a, b, mid + 1, r));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int tmax = 0, tmin = 1e9 + 1;
    REP(i, 1, n){
        cin >> a[i];
        tmax = max(tmax, a[i]);
        tmin = min(tmin, a[i]);
        a[i + n] = a[i];
    }
    if(tmin * 2 >= tmax){
        REP(i, 1, n) cout << -1 << " ";
        cout << endl;
        return 0;
    }
    REP(i, 1, 2 * n){
        auto pos = mp.upper_bound(MP(a[i] * 2, 2 * n + 1));
        vector<pii> to_be_removed;
        for(auto it = pos; it != mp.end(); ++it){
            to_be_removed.PB((*it));
            b[(*it).SE] = i;
        }
        for(auto v: to_be_removed){
            mp.erase(v);
        }
        if(!b[i]) mp.insert(MP(a[i], i));
    }
    REP(i, 1, 2 * n) if(!b[i]) b[i] = 1e9 + 1;
    build(1, 1, 2 * n);
    REP(i, 1, n) if(b[i] < 1e9 + 1){
        int res = min(b[i], query(1, i + 1, b[i], 1, 2 * n));
        ans[i] = res - i;
    }
    REP(i, 1, n) if(b[i] < 1e9 + 1){
        int last = (i - 1 < 1) ? n : i - 1, tot = 1;
        while(b[last] == 1e9 + 1){
            ans[last] = ans[i] + tot;
            last = (last - 1 < 1) ? n : last - 1;
            tot++;
        }
    }
    REP(i, 1, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
