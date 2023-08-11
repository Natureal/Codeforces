// Tree dp
#include <bits/stdc++.h>
using namespace std;
 
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
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
    for(int i = 1; i <= n; ++i) tmp[i][0] = tmp[i][1] = -1;
    dp[p][1][0] = 0, dp[p][1][1] = V[p];
    for(int i = 0; i < G[p].size(); ++i){
        int v = G[p][i];
        if(v == pre) continue;
        Dfs(v, p);
        for(int q = 1; q <= sz[v]; ++q) if(dp[v][q][0] != -1){
            for(int j = 1; j <= sz[p]; ++j) if(dp[p][j][0] != -1){
                // join
                Update(dp[v][q][0] - (dp[v][q][1] > 0) + dp[p][j][0], dp[v][q][1] + dp[p][j][1], tmp[j + q - 1][0], tmp[j + q - 1][1]);
                // seperate
                Update(dp[v][q][0] + dp[p][j][0], dp[p][j][1], tmp[j + q][0], tmp[j + q][1]);
            }
        }
        sz[p] += sz[v];
        for(int j = 1; j <= sz[p]; ++j) dp[p][j][0] = tmp[j][0], dp[p][j][1] = tmp[j][1], tmp[j][0] = tmp[j][1] = -1;
    }
    for(int j = 1; j <= sz[p]; ++j) dp[p][j][0] += (dp[p][j][1] > 0);
    //for(int j = 1; j <= sz[p]; ++j) printf("dp[%d][%d] %d %d\n", p, j, dp[p][j][0], dp[p][j][1]);
}
 
int main(){
	cin >> t;
    for(int o = 1; o <= t; ++o){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j][0] = dp[i][j][1] = -1;
        for(int i = 1; i <= n; ++i){
            int a;
            cin >> a;
            V[i] = -a;
            G[i].clear();
        }
        for(int i = 1; i <= n; ++i){
            int a;
            cin >> a;
            V[i] += a;
        }
        for(int i = 1; i < n; ++i){
            int a, b;
            cin >> a >> b;
            G[a].PB(b);
            G[b].PB(a);
        }
        Dfs(1, 0);
        cout << dp[1][m][0] << endl;
    }
    return 0;
}
