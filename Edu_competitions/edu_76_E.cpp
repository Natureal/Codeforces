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

int k[3];
int p[200010];
int dp[200010][3];

int main(){
    ios_base::sync_with_stdio(false);
	REP(i, 0, 2) cin >> k[i];
    REP(i, 0, 2){
        REP(j, 0, k[i] - 1){
            int a;
            cin >> a;
            p[a] = i;
        }
    }
    int sum = k[0] + k[1] + k[2];
    REP(i, 1, sum){
        dp[i][0] = dp[i - 1][0] + (p[i] == 0);
        dp[i][1] = (p[i] == 1) + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][2] = (p[i] == 2) + max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    }
    cout << sum - max(dp[sum][0], max(dp[sum][1], dp[sum][2])) << endl;
    return 0;
}
