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

int n, p[110];
int pre[110], rem_even = 0, rem_odd = 0;
int dp[110][110][2];

void Up(int &a, int b, int c){
    if(b == -1) return;
    if(a == -1) a = b + c;
    else a = min(a, b + c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    rem_even = n / 2;
    rem_odd = (n + 1) / 2;
    REP(i, 1, n){
        cin >> p[i];
        if(p[i] & 1) rem_odd--;
        if(p[i] && p[i] % 2 == 0) rem_even--;
        pre[i] = pre[i - 1];
        if(p[i] == 0) pre[i]++;
    }
    MEM(dp, -1);
    dp[0][0][0] = dp[0][0][1] = 0;
    REP(i, 1, n){
        REP(j, 0, min(pre[i], rem_even)){
            // need
            if(p[i] == 0){
            if(j){
                Up(dp[i][j][0], dp[i - 1][j - 1][0], 0);
                Up(dp[i][j][0], dp[i - 1][j - 1][1], 1);
            }
            if(pre[i] - j <= rem_odd){
                Up(dp[i][j][1], dp[i - 1][j][0], 1);
                Up(dp[i][j][1], dp[i - 1][j][1], 0);
            }
            }
            else{
            // no need
            Up(dp[i][j][p[i] & 1], dp[i - 1][j][p[i] & 1], 0);
            Up(dp[i][j][p[i] & 1], dp[i - 1][j][(p[i] & 1) ^ 1], 1);
            }
            //printf("dp[%d][%d]: %d %d\n", i, j, dp[i][j][0], dp[i][j][1]);
        }
    }
    int ans = 1e7;
    REP(i, 0, rem_even){
        if(dp[n][i][0] != -1) ans = min(ans, dp[n][i][0]);
        if(dp[n][i][1] != -1) ans = min(ans, dp[n][i][1]);
    }
    cout << ans << endl;
    return 0;
}
