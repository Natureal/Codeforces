// SCC, tarjan
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): *(s.find_by_order(2), counting from 0)
// order_of_key(k) returns the number of items strictly smaller than item k.
template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, 
        tree_order_statistics_node_update>;

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
const int maxn = 100010;

int m, d;

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

char g[100010][51];
VI SC[100010], G[100010], interG[100010 * 50];
int id[100010][51], idt, sum[100010 * 50], ans;
map<int, int> exis;

void Inside(int p, int cur){
   // printf("Inter: %d %d\n", p, cur);
    id[p][cur] = idt;
    if(exis[p] == 0 && g[p][cur] == '1') sum[idt]++, exis[p] = 1;
    for(auto v: G[p]){
        if(id[v][(cur + 1) % d]) continue;
        Inside(v, (cur + 1) % d);
    }
}

void Solve(int p, int val){
    ans = max(ans, val);
    for(auto v: interG[p]){
        Solve(v, val + sum[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> d;
    REP(i, 1, m){
        int a, b;
        cin >> a >> b;
        T_g[a].PB(b);
    }
    REP(i, 1, n) cin >> g[i];
    Tarjan();
    //printf("scnt : %d\n", scnt);
    REP(k, 1, n){
        SC[sc[k]].PB(k);
        for(auto v: T_g[k]){
            if(sc[k] == sc[v]){
                G[k].PB(v);
                //printf("inside sc : %d -> %d\n", k, v);
            }
        }
    }
    REP(i, 1, scnt){
        for(auto v: SC[i]){
            REP(j, 0, d - 1) if(id[v][j] == 0){
                ++idt;
                exis.clear();
                Inside(v, j);
                //printf("%d %d, sum[%d]: %d\n", v, j, idt, sum[idt]);
            }
        }       
    }
    REP(k, 1, n){
        for(auto v: T_g[k]){
            if(sc[k] != sc[v]){
                REP(j, 0, d - 1){
                    int nj = (j + 1) % d;
                    interG[id[k][j]].PB(id[v][nj]);
                    //printf("inter: %d %d\n", id[k][j], id[v][nj]);
                }
            }
        }
    }
    Solve(id[1][0], sum[id[1][0]]);
    cout << ans << endl;
    return 0;
}
