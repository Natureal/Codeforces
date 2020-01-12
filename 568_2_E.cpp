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

int t, n, m;
char g[2010][2010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> m;
        vector<pii > V[26];
        REP(i, 1, n) cin >> g[i] + 1;
        REP(i, 1, n){
            REP(j, 1, m){
                if(g[i][j] != '.'){
                    V[g[i][j] - 'a'].PB(MP(i, j));
                }
            }
        }
        REP(i, 0, 25) sort(V[i].begin(), V[i].end());
        bool f = true;
        REP(i, 0, 25) if(SZ(V[i])){
            int sz = SZ(V[i]);
            bool sx = false, sy = false;;
            sx = (V[i][0].FI == V[i][sz - 1].FI);
            sy = (V[i][0].SE == V[i][sz - 1].SE);
            if(!sx && !sy){
                f = false;
                break;
            }
            REP(j, 1, sz - 2){
                if(sx && V[i][j].FI != V[i][0].FI){
                    f = false;
                }
                if(sy && V[i][j].SE != V[i][0].SE){
                    f = false;
                }
                if(!f) break;
            }
            int x = V[i][0].FI, y = V[i][0].SE;
            int dir[2];
            if(sx) dir[0] = 0, dir[1] = 1;
            else dir[0] = 1, dir[1] = 0;
            while(!(x == V[i][sz - 1].FI && y == V[i][sz - 1].SE)){
                if(g[x][y] - 'a' < i){
                    f = false;
                    break;
                }
                x += dir[0];
                y += dir[1];
            }
            if(!f) break;
        }
        if(!f) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            int num = 0, last = -1;
            REP(i, 0, 25) if(SZ(V[i])) last = i;
            cout << last + 1 << endl;
            REP(i, 0, 25){
                int sz = SZ(V[i]);
                if(sz)
                    cout << V[i][0].FI << " " << V[i][0].SE << " " << V[i][sz - 1].FI << " "
                        << V[i][sz - 1].SE << endl;
                else if(i < last){
                    cout << V[last][0].FI << " " << V[last][0].SE << " " << V[last][0].FI << " "
                        << V[last][0].SE << endl;
                }
            }
        }
    }
    return 0;
}
