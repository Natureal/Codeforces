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

int n, q;
VI G[100010];
int fa[26][100010], dep[100010], sz[100010];

void Dfs(int p, int pre, int d){
    fa[0][p] = pre;
    dep[p] = d;
    sz[p] = 1;
    for(auto v: G[p]){
        if(v == pre) continue;
        Dfs(v, p, d + 1);
        sz[p] += sz[v];
    }
}

void Pre(){
    Dfs(1, -1, 0);
    for(int k = 0; k + 1 < 26; ++k){
        for(int v = 1; v <= n; ++v){
            if(fa[k][v] < 0) fa[k + 1][v] = -1;
            else fa[k + 1][v] = fa[k][fa[k][v]];
        }
    }
}

int Lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    for(int k = 25; k >= 0; --k){
        if((dep[v] - dep[u]) & (1 << k)){
            v = fa[k][v];
        }
    }
    if(u == v) return u;
    for(int k = 25; k >= 0; --k){
        if(fa[k][u] != fa[k][v]){
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    return fa[0][u];
}

int Dis(int u, int v){
    int lca = Lca(u, v);
    return dep[u] - dep[lca] + dep[v] - dep[lca];
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
    Pre();
    cin >> q;
    REP(i, 1, q){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int dis1 = Dis(a, b), dis2 = Dis(a, x) + Dis(b, y) + 1, dis3 = Dis(a, y) + Dis(b, x) + 1;
        bool f = false;
        if(k >= dis1 && (k - dis1) % 2 == 0) f = true;
        if(k >= dis2 && (k - dis2) % 2 == 0) f = true;
        if(k >= dis3 && (k - dis3) % 2 == 0) f = true;
        cout << (f ? "YES": "NO") << endl;
    }
    return 0;
}
