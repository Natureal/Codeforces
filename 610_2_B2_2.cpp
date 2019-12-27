// DP
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

int t, n, p, k, a[200010];
ll dp[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        MEM(dp, 0);
        cin >> n >> p >> k;
        REP(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = 0;
        REP(i, 1, n){
            if(i < k){
                dp[i] = dp[i - 1] + a[i];
                if(dp[i] <= p) ans = i;
            }
            else{
                dp[i % k] += a[i];
                if(dp[i % k] <= p) ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
