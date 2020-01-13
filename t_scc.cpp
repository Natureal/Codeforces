// Do not forget to define maxn
const int maxn = ;

int n, low[maxn], dfn[maxn], sc[maxn], T_tot, scnt, cnt[maxn];
stack<int> T_st;
VI T_g[maxn];

void T_dfs(int p){
    low[p] = dfn[p] = ++T_tot;
    T_st.push(p);
    for(auto v: T_g[p]){
        if(!dfn[v]){
            T_dfs(v);
            low[p] = min(low[p], low[v]);
        }
        else if(!sc[v]){
            low[p] = min(low[p], dfn[v]);
        }
    }
    if(low[p] == dfn[p]){
        ++scnt;
        while(1){
            int x = T_st.top(); T_st.pop();
            sc[x] = scnt;
            cnt[scnt]++;
            if(x == p) break;
        }
    }
}

void Tarjan(){
    MEM(low, 0); MEM(dfn, 0); MEM(sc, 0);
    while(!T_st.empty()) T_st.pop();
    REP(i, 1, n) if(!dfn[i]) T_dfs(i);
}
