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
typedef pair<int,int> pii;
typedef vector<int> VI;
const int mod = 1000000007;

int t, n, m, a[200010];
pii S[200010];
int SF[200010];
int c[200010 << 2];

void build(int p, int l, int r){
    if(l == r){
        c[p] = a[l];
        return;
    }
    int mid = getmid(l, r);
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    c[p] = max(c[p << 1], c[p << 1|1]);
}

int get(int p, int a, int b, int l, int r){
    if(a <= l && r <= b){
        return c[p];
    }
    int mid = getmid(l, r);
    int ans = 0;
    if(a <= mid) ans = max(ans, get(p << 1, a, b, l, mid));
    if(b >= mid + 1) ans = max(ans, get(p << 1|1, a, b, mid + 1, r));
    return ans;
}

bool check(int p, int mid){
    int tmax = get(1, p + 1, mid, 1, n);
    int pos = lower_bound(SF + 1, SF + m + 1, tmax) - SF;
    if(S[pos].SE >= mid - p){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        build(1, 1, n);
        cin >> m;
        REP(i, 1, m){
            cin >> S[i].FI >> S[i].SE;
        }
        sort(S + 1, S + m + 1);
        if(get(1, 1, n, 1, n) > S[m].FI){
            cout << -1 << endl;
            continue;
        }
        REP(i, 1, m) SF[i] = S[i].FI;
        DEC(i, m - 1, 1) S[i].SE = max(S[i].SE, S[i + 1].SE);
        int p = 0, ans = 0;
        while(p < n){
            int l = p + 1, r = n;
            while(l < r){
                int mid = getmid(l, r);
                if(check(p, mid)) l = mid + 1;
                else r = mid;
            }
            if(l > n || !check(p, l)) l--;
            //printf("p : %d , l : %d\n", p, l);
            p = l;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
