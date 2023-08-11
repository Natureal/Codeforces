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

int T;
char s[100010], t[100010];
int nxt[100010][26];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> s + 1 >> t + 1;
        int ls = strlen(s + 1), lt = strlen(t + 1);
        MEM(nxt, -1);
        DEC(i, ls, 1){
            REP(j, 0, 25){
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }
        REP(i, 1, ls){
            REP(j, 0, 25){
                if(nxt[i][j] == -1) nxt[i][j] = nxt[1][j];
            }
        }
        int p = 1, ans = 1;
        REP(i, 1, lt){
            if(p > ls) ans++, p = 1;
            if(s[p] != t[i]){
                int np = nxt[p][t[i] - 'a'];
                if(np == -1){
                    ans = -1;
                    break;
                }
                if(np < p) ans++;
                p = np;
            }
            p++;
        }
        cout << ans << endl;
    }
    return 0;
}
