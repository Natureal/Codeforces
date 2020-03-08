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
const int INF = (1 << 30) - 1;

int n, m;
int l[2010], s[2010], c[4010], num[2010];
int dp[2010][1 << 11];

int cal(int a, int sta){
    int res = 0;
    REP(i, 0, 10) if(sta & (1 << i)){
        res += c[a + i];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n) cin >> l[i];
    REP(i, 1, n) cin >> s[i];
    REP(i, 1, n + m) cin >> c[i];
    REP(i, 1, n){
        REP(j, 0, (1 << 11) - 1) dp[i][j] = -INF;
        dp[i][0] = 0;
    }
    DEC(i, n, 1){
        DEC(j, l[i], 1){
            DEC(k, num[j], 0) if(dp[j][k] != -INF){
                int tk = (l[i] - j > 11) ? 0 : (k >> (l[i] - j)), tk2 = tk + 1;
                //printf("i: %d, li: %d, j: %d, tk: %d, tk2: %d\n", i, l[i], j, tk, tk2);
                dp[l[i]][tk2] = max(dp[l[i]][tk2], dp[j][k] - s[i] + cal(l[i], tk ^ tk2));
                //printf("dp[%d][%d] -> dp[%d][%d]: %d\n", j, k, l[i], tk2, dp[l[i]][tk2]);
                num[l[i]] = max(num[l[i]], tk2);
            }
        }
    }
    int ans = 0;
    REP(i, 1, m){
        REP(j, 0, (1 << 11) - 1) ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
    return 0;
}
