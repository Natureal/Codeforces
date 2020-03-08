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

int n;
pii G[1010][1010];
int g[1010][1010];
int vis[1010][1010];
int ans[1010][1010];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Dfs(int a, int b){
    //printf("dfs %d %d\n", a, b);
    if(g[a][b] == -1){
        vis[a][b] = 1;
        bool f = false;
        REP(k, 0, 3){
            int ta = a + dir[k][0], tb = b + dir[k][1];
            if(ta < 1 || ta > n || tb < 1 || tb > n) continue;
            if(g[ta][tb] == -1){
                if(f == false){
                    ans[a][b] = k + 1;
                }
                f = true;
                if(!vis[ta][tb]){
                    Dfs(ta, tb);
                }
            }
        }
    }
    else{
        vis[a][b] = 1;
        REP(k, 0, 3){
            int ta = a + dir[k][0], tb = b + dir[k][1];
            if(ta < 1 || ta > n || tb < 1 || tb > n || vis[ta][tb]) continue;
            if(G[a][b] == G[ta][tb]){
                ans[ta][tb] = (k ^ 1) + 1;
                Dfs(ta, tb);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    bool f = true;
    REP(i, 1, n){
        REP(j, 1, n){
            cin >> G[i][j].FI >> G[i][j].SE;
        }
    }
    REP(i, 1, n){
        REP(j, 1, n){
            if(G[i][j].FI == -1){
                if(g[i][j] != 0){
                    f = false;
                }
                g[i][j] = -1;
            }
            else{
                int a = G[i][j].FI, b = G[i][j].SE;
                if(g[a][b] == -1){
                    f = false;
                }
                if(G[a][b] != G[i][j]){
                    f = false;
                }
                g[a][b] = 5;
                ans[a][b] = 5;
            }
        }
    }
    if(!f){
        cout << "INVALID" << endl;
    }
    else{
        REP(i, 1, n){
            REP(j, 1, n) if(g[i][j] == -1 || g[i][j] == 5){
                if(!vis[i][j]){
                    Dfs(i, j);
                }
            }
        }
        REP(i, 1, n){
            REP(j, 1, n){
                if(ans[i][j] == 0) f = false;
            }
        }
        if(!f) cout << "INVALID" << endl;
        else{
            cout << "VALID" << endl;
            REP(i, 1, n){
                REP(j, 1, n){
                    if(ans[i][j] == 1) cout << "U";
                    else if(ans[i][j] == 2) cout << "D";
                    else if(ans[i][j] == 3) cout << "L";
                    else if(ans[i][j] == 4) cout << "R";
                    else cout << "X";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
