// DP, exponent
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
const int mod = 1000000007;
const int maxn = (1 << 18) + 1;

int n, a[maxn], tot, pre[19];
ll dp[maxn][19];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    bool st = false;
    REP(i, 1, n){
        int v;
        cin >> v;
        if(st){
            a[++tot] = v;
        }
        if(v == -1) st = true;
    }
    reverse(a + 1, a + tot + 1);
    int base = n / 2, top = 1;
    REP(i, 1, 18){
        pre[i] = pre[i - 1] + base - 1;
        base /= 2;
        top = i;
        if(base <= 0) break;
    }
    MEM(dp, -1);
    dp[0][0] = 0;
    REP(i, 1, tot){
        REP(j, 1, min(i, top)){
            if(dp[i - 1][j - 1] != -1) dp[i][j] = dp[i - 1][j - 1] + a[i];
            if(pre[j] >= i - j && dp[i - 1][j] != -1){
                if(dp[i][j] == -1) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            //printf("dp[%d][%d]: %lld\n", i, j, dp[i][j]);
        }
    }
    ll ans = (1LL << 62) - 1;
    REP(i, 0, top) if(dp[tot][i] != -1){
        ans = min(ans, dp[tot][i]);
    }
    cout << ans << endl;
    return 0;
}
