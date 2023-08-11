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
typedef vector<int> VI;
const int mod = 1000000007;

int n, m;
int dp[81][100010];
pii X[81];

void Update(int &a, int b){
    if(b == -1) return;
    if(a == -1) a = b;
    else a = min(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        cin >> X[i].FI >> X[i].SE;
    }
    sort(X + 1, X + n + 1);
    MEM(dp, -1);
    REP(i, 0, n){
        dp[i][0] = 0;
    }
    REP(i, 1, n){
        REP(j, 1, m){
            Update(dp[i][j], dp[i - 1][j]);
        }
        Update(dp[i][min(m, X[i].FI + X[i].SE)], dp[i - 1][max(0, X[i].FI - X[i].SE - 1)]);
        REP(j, 1, m){
            if(X[i].FI + X[i].SE + j > m + 1 && X[i].FI - X[i].SE - j - 1 < -1) break;
            if(dp[i - 1][max(0, X[i].FI - X[i].SE - j - 1)] == -1) continue;
            Update(dp[i][min(m, X[i].FI + X[i].SE + j)], dp[i - 1][max(0, X[i].FI - X[i].SE - j - 1)] + j);
        }
        DEC(j, m - 1, 1){
            Update(dp[i][j], dp[i][j + 1]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
