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

int n, p, k;

struct P{
    int a;
    VI s;
}pe[100010];

ll dp[100010][1 << 7];

int num[1 << 7];

bool cmp(P a, P b){
    return a.a > b.a;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> p >> k;
    REP(sta, 0, (1 << p) - 1){
        int c = 0;
        REP(j, 0, p - 1){
            if(sta & (1 << j)) c++;
        }
        num[sta] = c;
    }
    REP(i, 1, n){
        cin >> pe[i].a;
    }
    REP(i, 1, n){
        REP(j, 1, p){
            int a;
            cin >> a;
            pe[i].s.PB(a);
        }
    }
    sort(pe + 1, pe + n + 1, cmp);
    MEM(dp, -1);
    dp[0][0] = 0;
    ll ans = 0;
    REP(i, 1, n){
        REP(sta, 0, (1 << p) - 1){
            int plus = (i - 1 - num[sta] >= k) ? 0 : pe[i].a;
            if(dp[i - 1][sta] != -1) dp[i][sta] = max(dp[i][sta], dp[i - 1][sta] + plus);
            REP(j, 0, p - 1){
                if(sta & (1 << j))
                    if(dp[i - 1][sta ^ (1 << j)] != -1)
                        dp[i][sta] = max(dp[i][sta], dp[i - 1][sta ^ (1 << j)] + pe[i].s[j]);
            }
            //printf("dp[%d][%d]: %lld\n", i, sta, dp[i][sta]);
        }
        ans = max(ans, dp[i][(1 << p) - 1]);
    }
    cout << ans << endl;
    return 0;
}
