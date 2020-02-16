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
 
int n, m, q;
char g[510][510];
int w[251][501][501];
 
int Cal(int l, int a1, int b1, int a2, int b2){
    return w[l][a2][b2] - w[l][a2][b1 - 1] - w[l][a1 - 1][b2] + w[l][a1 - 1][b1 - 1];
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
    REP(i, 1, n){
        cin >> g[i] + 1;
    }
    int top = min(n, m) / 2;
    REP(i, 1, n - 1){
        REP(j, 1, m - 1) if(g[i][j] == 'R' && g[i][j + 1] == 'G'
                && g[i + 1][j] == 'Y' && g[i + 1][j + 1] == 'B'){
            w[1][i][j] = 1;
            //printf("w %d %d %d\n", 1, i, j);
            REP(l, 2, top){
                // R
                bool f = true;
                int tn1 = i - l + 1, tn2 = i;
                if(tn1 < 1) break;
                int tm1 = j - l + 1, tm2 = j;
                if(tm1 < 1) break;
                REP(k, tm1, tm2) if(g[tn1][k] != 'R') f = false;
                REP(k, tn1, tn2) if(g[k][tm1] != 'R') f = false;
                if(!f) break;
                // G
                tm1 = j + 1, tm2 = j + l;
                if(tm2 > m) break;
                REP(k, tm1, tm2) if(g[tn1][k] != 'G') f = false;
                REP(k, tn1, tn2) if(g[k][tm2] != 'G') f = false;
                if(!f) break;
                // Y
                tn1 = i + 1, tn2 = i + l;
                if(tn2 > n) break;
                tm1 = j - l + 1, tm2 = j;
                if(tm1 < 1) break;
                REP(k, tm1, tm2) if(g[tn2][k] != 'Y') f = false;
                REP(k, tn1, tn2) if(g[k][tm1] != 'Y') f = false;
                if(!f) break;
                // B
                tm1 = j + 1, tm2 = j + l;
                if(tm2 > m) break;
                REP(k, tm1, tm2) if(g[tn2][k] != 'B') f = false;
                REP(k, tn1, tn2) if(g[k][tm2] != 'B') f = false;
                if(!f) break;
                w[l][i - l + 1][j - l + 1] = 1;
                //printf("w %d %d %d\n", l, i - l + 1, j - l + 1);
            }
        }
    }
    REP(l, 1, top){
        int tn = n - l - l + 1, tm = m - l - l + 1;
        REP(i, 1, tn){
            REP(j, 1, tm){
                w[l][i][j] = w[l][i][j] + w[l][i - 1][j] + w[l][i][j - 1] - w[l][i - 1][j - 1];
            }
        }
    }
    REP(i, 1, q){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int ans = 0;
        REP(l, 1, top){
            int ta2 = a2 - l - l + 1;
            int tb2 = b2 - l - l + 1;
            if(a1 <= ta2 && b1 <= tb2){
                int res = Cal(l, a1, b1, ta2, tb2);
                //printf("%d (%d %d) (%d %d) res: %d\n", l, a1, b1, ta2, tb2, res);
                if(res > 0){
                    ans = 4 * l * l;
                }
                else break;
            }
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}
