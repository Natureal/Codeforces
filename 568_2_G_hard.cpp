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
const int mod = 1000000007;

int n, T;
int t[51], g[51];
int dp[3][2501][51], cnt[51][51][51][3];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> T;
    REP(i, 1, n){
        cin >> t[i] >> g[i];
        g[i]--;
    }
    dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = 1;
    int pre[3] = {0}, sum[3] = {0};
    REP(i, 1, n){
        pre[g[i]]++;
        sum[g[i]] += t[i];
        for(int j = sum[g[i]]; j >= t[i]; --j){
            for(int k = 1; k <= pre[g[i]]; ++k) if(dp[g[i]][j - t[i]][k - 1]){
                dp[g[i]][j][k] = (dp[g[i]][j][k] + dp[g[i]][j - t[i]][k - 1]) % mod;
            }
        }
    }
    REP(i, 0, pre[0]){
        REP(j, 0, pre[1]){
            REP(k, 0, pre[2]){
                for(int q = 0; q < 3; ++q){
                    if((q == 0 && !i) || (q == 1 && !j) || (q == 2 && !k)) continue;
                    if(q == 0){
                        if(i - 1 == 0 && j == 0 && k == 0) cnt[i][j][k][0] = 1;
                        else cnt[i][j][k][0] = 1LL * (cnt[i - 1][j][k][1] + 
                                cnt[i - 1][j][k][2]) % mod * i % mod;
                    }
                    else if(q == 1){
                        if(i == 0 && j - 1 == 0 && k == 0) cnt[i][j][k][1] = 1;
                        else cnt[i][j][k][1] = 1LL * (cnt[i][j - 1][k][0] +
                                cnt[i][j - 1][k][2]) % mod * j % mod;
                    }
                    else{
                        if(i == 0 && j == 0 && k - 1 == 0) cnt[i][j][k][2] = 1;
                        else cnt[i][j][k][2] = 1LL * (cnt[i][j][k - 1][0] + 
                                cnt[i][j][k - 1][1]) % mod * k % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    REP(k0, 0, pre[0]){
        REP(k1, 0, pre[1]){
            REP(k2, 0, pre[2]){
                if(k0 + k1 < k2 - 1 || k0 + k2 < k1 - 1 || k1 + k2 < k0 - 1) continue;
                int tcnt = ((cnt[k0][k1][k2][0] + cnt[k0][k1][k2][1]) % mod
                    + cnt[k0][k1][k2][2]) % mod;
                REP(i0, k0, min(T, sum[0])) if(dp[0][i0][k0]){
                    REP(i1, k1, min(T - i0 - k2, sum[1])) if(dp[1][i1][k1]){
                        if(dp[2][T - i0 - i1][k2]){
                            //printf("%d %d %d, t %d\n", k0, k1, k2, tcnt);
                            ans = (ans + 1LL * dp[0][i0][k0] * dp[1][i1][k1] % mod
                                    * dp[2][T - i0 - i1][k2] % mod * tcnt % mod) % mod;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
