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

int h, w, r[1010], c[1010];
int g[1010][1010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> h >> w;
    REP(i, 1, h){
        cin >> r[i];
        REP(j, 1, r[i]) g[i][j] = 1;
    }
    REP(i, 1, w){
        cin >> c[i];
        REP(j, 1, c[i]) g[j][i] = 1;
    }
    int ans = 1;
    REP(i, 1, h){
        if(g[i][r[i] + 1] == 1){
            ans = 0;
            break;
        }
        REP(j, r[i] + 2, w) if(g[i][j] == 0){
            g[i][j] = -1;
            //printf("%d , %d\n", i, j);
        }
    }
    if(ans == 0){
        cout << ans << endl;
        return 0;
    }
    REP(i, 1, w){
        if(g[c[i] + 1][i] == 1){
            ans = 0;
            break;
        }
        REP(j, c[i] + 2, h) if(g[j][i] == -1){
            g[j][i] = -2;
            ans = 2LL * ans % mod;
            //printf("good %d , %d\n", j, i);
        }
    }
    cout << ans << endl;
    return 0;
}
