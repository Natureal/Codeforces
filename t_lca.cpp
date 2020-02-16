const int maxn = ;
const int maxlog = log(maxn) / log(2) + 1; // (1 << 15) = 32768

VI G[maxn];
int n, fa[maxlog][maxn], dep[maxn];

void Dfs(int p, int pre, int d){
    fa[0][p] = pre;
    dep[p] = d;
    for(auto v: G[p]){
        if(v == pre) continue;
        Dfs(v, p, d + 1);
    }
}

void Pre(){
    Dfs(1, -1, 0);
    for(int k = 0; k + 1 < maxlog; ++k){
        for(int v = 1; v <= n; ++v){ // n: number of nodes in the tree
            if(fa[k][v] < 0) fa[k + 1][v] = -1;
            else fa[k + 1][v] = fa[k][fa[k][v]];
        }
    }
}

int Lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    for(int k = maxlog - 1; k >= 0; --k){
        if((dep[v] - dep[u]) & (1 << k)){
            v = fa[k][v];
        }
    }
    if(u == v) return u;
    for(int k = maxlog - 1; k >= 0; --k){
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
