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

int T, ls, lt;
char s[410], t[410];
int dp[410][410];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> s + 1 >> t + 1;
        ls = strlen(s + 1);
        lt = strlen(t + 1);
        bool f = false;
        REP(i, 1, lt){
            // [1, i], [i + 1, lt]
            MEM(dp, -1);
            dp[0][0] = 0;
            REP(a, 1, ls){
                REP(b, 0, min(i, a)){
                    int plus = 0;
                    if(dp[a - 1][b] != -1 && dp[a - 1][b] + i + 1 <= lt &&
                            s[a] == t[dp[a - 1][b] + i + 1]) plus = 1;
                    dp[a][b] = dp[a - 1][b] + plus;
                    if(b > 0 && s[a] == t[b]){
                        dp[a][b] = max(dp[a][b], dp[a - 1][b - 1]);
                    }
                }
            }
            if(dp[ls][i] != -1 && dp[ls][i] + i == lt){
                f = true;
                //printf("yes: %d\n", i);
                break;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
