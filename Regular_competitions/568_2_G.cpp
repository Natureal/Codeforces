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

int n, T, t[20], g[20];
int dp[16][1 << 15][3];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> T;
    REP(i, 0, n - 1){
        cin >> t[i] >> g[i];
        g[i]--;
        dp[0][1 << i][g[i]] = 1;
    }
    REP(i, 1, n - 1){
        for(int s = 0; s < (1 << n); ++s){
            for(int j = 0; j < n; ++j) if(!(s & (1 << j))){
                if(s == 0){
                    dp[i][s | (1 << j)][g[j]] = 1;
                    continue;
                }
                for(int pre = 0; pre < 3; ++pre) if(pre != g[j]){
                    dp[i][s | (1 << j)][g[j]] = (dp[i][s | (1 << j)][g[j]] + 
                            dp[i - 1][s][pre]) % mod;
                    //printf("dp[%d][%d][%d] : %d\n", i - 1, s, pre, dp[i - 1][s][pre]);
                }
            }
        }
    }
    int ans = 0;
    for(int s = 0; s < (1 << n); ++s){
        int time = 0;
        for(int j = 0; j < n; ++j) if(s & (1 << j)) time += t[j];
        if(time == T){
            for(int pre = 0; pre < 3; ++pre){
                ans = (ans + dp[n - 1][s][pre]) % mod;
                //printf("dp[%d][%d]: %d\n", s, pre, dp[n - 1][s][pre]);
            }       
        }
    }
    cout << ans << endl;
    return 0;
}
