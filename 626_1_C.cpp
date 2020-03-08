#pragma GCC optimize("O3")
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
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;
const int B = 239;

int t, n, m;
int H[500010];
pll Hash[500010];

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    H[0] = 1;
    REP(i, 1, 500000) H[i] = 1LL * H[i - 1] * B % mod;
    scanf("%d", &t);
    REP(q, 1, t){
        scanf("%d%d", &n, &m);
        REP(i, 1, n) scanf("%lld", &Hash[i].SE), Hash[i].FI = -1;
        REP(i, 1, m){
            int a, b;
            scanf("%d%d", &a, &b);
            if(Hash[b].FI == -1) Hash[b].FI = H[a];
            else Hash[b].FI = (Hash[b].FI + H[a]) % mod;
        }
        ll ans = -1, cur = 0;
        sort(Hash + 1, Hash + n + 1);
        REP(i, 1, n) if(Hash[i].FI != -1){
            cur += Hash[i].SE;
            if(i < n && Hash[i].FI != Hash[i + 1].FI){
                if(ans == -1) ans = cur;
                else ans = __gcd(ans, cur);
                cur = 0;
            }
        }
        if(cur > 0) ans = (ans == -1) ? cur : __gcd(ans, cur);
        printf("%lld\n", ans);
    }
    return 0;
}
