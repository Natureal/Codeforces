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
const double eps = 1e-8;
const ll INF = (1LL << 62) - 1;
const int MAXN = 100010;

int t, n, m;
int V[3010], sz[3010];
ll dp[3010][3010][2];
vector<int> G[3010];

void Update(ll a, ll b, ll &c, ll &d){
    if(a > c)
        c = a, d = b;
    else if(a == c)
        d = max(d, b);
}

void Dfs(int p, int pre){
    sz[p] = 1;
    ll tmp[3010][2];
    REP(i, 0, n) tmp[i][0] = tmp[i][1] = -1;
    dp[p][0][0] = 0, dp[p][0][1] = V[p];
    REP(i, 0, SZ(G[p]) - 1){
        int v = G[p][i];
        if(v == pre) continue;
        Dfs(v, p);
        REP(q, 0, sz[v]) if(dp[v][q][0] != -1){
            REP(j, 0, sz[p]) if(dp[p][j][0] != -1){
                Update(dp[v][q][0] + dp[p][j][0], dp[v][q][1] + dp[p][j][1], tmp[q + j][0], tmp[q + j][1]);
            }
        }
        sz[p] += sz[v];
        REP(j, 0, sz[p]){
            dp[p][j][0] = tmp[j][0], dp[p][j][1] = tmp[j][1];
            tmp[j][0] = tmp[j][1] = -1;
        }
    }
    DEC(j, sz[p] - 1, 0){
        Update(dp[p][j][0] + (dp[p][j][1] > 0), 0, dp[p][j + 1][0], dp[p][j + 1][1]);
    }
    //REP(j, 0, sz[p]) printf("dp[%d][%d]: %d %d\n", p, j, dp[p][j][0], dp[p][j][1]);
}

int main(){
	cin >> t;
    while(t--){
        cin >> n >> m;
        REP(i, 0, n) REP(j, 0, n) dp[i][j][0] = dp[i][j][1] = -1;
        REP(i, 1, n){
            int a;
            cin >> a;
            V[i] = -a;
            G[i].clear();
        }
        REP(i, 1, n){
            int a;
            cin >> a;
            V[i] += a;
        }
        REP(i, 1, n - 1){
            int a, b;
            cin >> a >> b;
            G[a].PB(b);
            G[b].PB(a);
        }
        Dfs(1, 0);
        cout << dp[1][m - 1][0] + (dp[1][m - 1][1] > 0) << endl;
    }
    return 0;
}
