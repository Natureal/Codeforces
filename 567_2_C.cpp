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

int n, m;
char g[1010][1010];
int r[1010][1010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        cin >> g[i] + 1;
    }
    REP(i, 1, n){
        DEC(j, m, 1){
            r[i][j] = 1;
            if(g[i][j] == g[i][j + 1]) r[i][j] += r[i][j + 1];
        }
    }
    ll ans = 0;
    REP(j, 1, m){
        vector<pii > V;
        REP(i, 1, n){
            int ti = i;
            while(ti + 1 <= n && g[ti + 1][j] == g[i][j]) ti++;
            V.PB(MP(i, ti - i + 1));
            i = ti;
        }
        REP(i, 1, SZ(V) - 2){
            if(V[i - 1].SE >= V[i].SE && V[i + 1].SE >= V[i].SE){
                int tmin = 1e9;
                REP(k, V[i].FI - V[i].SE, V[i].FI + 2 * V[i].SE - 1){
                    tmin = min(tmin, r[k][j]);
                }
                //printf("[%d , %d], %d\n", V[i].FI - V[i].SE, V[i].FI + 2 * V[i].SE - 1, tmin);
                ans += tmin;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
