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
const int maxn = 3010;

int n;
VI G[maxn];
int sz[maxn][maxn], fa[maxn][maxn];
ll dp[maxn][maxn];

void Dfs(int p, int root, int pre){
    sz[root][p] = 1;
    fa[root][p] = pre;
    for(auto v: G[p]) if(v != pre){
        Dfs(v, root, p);
        sz[root][p] += sz[root][v];
    }
}

ll Solve(int a, int b){
    if(dp[a][b]) return dp[a][b];
    if(fa[b][a] == b || fa[a][b] == a) return dp[a][b] = dp[b][a] = 1LL * sz[a][b] * sz[b][a];
    return dp[a][b] = dp[b][a] = 
        max(Solve(fa[b][a], b), Solve(fa[a][b], a)) + 1LL * sz[a][b] * sz[b][a];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n - 1){
        int a, b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    REP(i, 1, n){
        Dfs(i, i, -1);
    }
    ll ans = 0;
    REP(i, 1, n){
        REP(j, i + 1, n) if(!dp[i][j]){
            Solve(i, j);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
