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

ll n, k;
ll a[100010], pre[100010];

bool check(ll v){
    ll res = (1LL << 62) - 1;
    REP(i, 1, n){
        ll tmp = 0;
        int pos = lower_bound(a + 1, a + n + 1, a[i] - v) - a;
        if(pos - 1 >= 1){
            tmp += (pos - 1) * (a[i] - v) - pre[pos - 1];
        }
        if(i + 1 <= n){
            tmp += pre[n] - pre[i] - (n - i) * a[i];
        }
        res = min(res, tmp);
    }
    REP(i, 1, n){
        ll tmp = 0;
        int pos = upper_bound(a + 1, a + n + 1, a[i] + v) - a;
        if(i - 1 >= 1)
            tmp += (i - 1) * a[i] - pre[i - 1];
        if(pos <= n)
            tmp += pre[n] - pre[pos - 1] - (n - pos + 1) * (a[i] + v);
        res = min(res, tmp);
    }
    return res <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
    REP(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    REP(i, 1, n) pre[i] = pre[i - 1] + a[i];
    int l = 0, r = 1e9;
    while(l < r){
        int mid = getmid(l, r);
        if(check((ll)mid)) r = mid;
        else l = mid + 1;
    }
    if(check(l) == false) l--;
    cout << l << endl;
    return 0;
}
