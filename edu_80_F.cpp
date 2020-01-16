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
const int INF = 1e6;

const int MAXN = 2010;
const int MAXM = 4010;

struct edge{
    int u,v,next,cost,cp,id;
};

struct MCMF{
    edge e[MAXM];
    int sou,sin;
    int first[MAXN],ecnt;
    int dis[MAXN];
    int prev[MAXN],pree[MAXN],inq[MAXN];
    void init(int a,int b){
        sou = a;
        sin = b;
        memset(first,-1,sizeof(first));
        ecnt = 0;
    }
    void add_edge(int u,int v,int cap, int fee, int id = 0){
        e[ecnt].u = u;
        e[ecnt].next = first[u];
        e[ecnt].v = v;
        e[ecnt].id = id;
        e[ecnt].cp = cap;
        e[ecnt].cost = fee;
        first[u] = ecnt++;
        
        e[ecnt].u = v;
        e[ecnt].next = first[v];
        e[ecnt].v = u;
        e[ecnt].cp = 0;
        e[ecnt].cost = -fee;
        first[v] = ecnt++;
    }
    bool Spfa(){
        fill(dis,dis + MAXN,INF);
        dis[sou] = 0;
        MEM(prev,-1),MEM(inq,0);
        queue<int> Q;
        Q.push(sou);
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            inq[x] = 0;
            for(int i = first[x]; ~i; i = e[i].next){
                if(e[i].cp <= 0) continue;
                int v = e[i].v;
                if(dis[x] + e[i].cost < dis[v]){
                    dis[v] = dis[x] + e[i].cost;
                    prev[v] = x;
                    pree[v] = i;
                    if(inq[v] == 0){
                        inq[v] = 1;
                        Q.push(v);
                    }
                }
            }
        }
        return prev[sin] != -1;
    }
    pii Solve(){
        int sumf = 0;
        int min_cost = 0;
        while(Spfa()){
            int minf = INF;
            for(int i = sin; i != sou; i = prev[i]){
                int id = pree[i];
                minf = min(minf,e[id].cp);
            }
            if(dis[sin] >= 0) break;
            for(int i = sin; i != sou; i = prev[i]){
                int id = pree[i];
                e[id].cp -= minf;
                e[id ^ 1].cp += minf;
            }
            sumf += minf;
            min_cost += dis[sin] * minf;
        }
        return MP(sumf, min_cost);
    }
}MC;

int n1, n2, m, c[2];
char g[2][210], col[410];
int e_co[210];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n1 >> n2 >> m >> c[0] >> c[1];
    cin >> g[0] >> g[1];
    int st = 801, ed = 802, need = n1 + n2;
    MC.init(st, ed);
    MEM(e_co, -1);
    REP(i, 1, n1 + n2){
        col[i] = (i <= n1) ? g[0][i - 1] : g[1][i - n1 - 1];
        if(col[i] == 'U'){
            need--;
            MC.add_edge(st, i, 200, 0);
            MC.add_edge(i, ed, 200, 0);
        }
        else if(col[i] == 'R'){
            if(i <= n1) MC.add_edge(st, i, 1, -INF), MC.add_edge(st, i, 200, 0);
            else MC.add_edge(i, ed, 1, -INF), MC.add_edge(i, ed, 200, 0);
        }
        else{
            if(i <= n1) MC.add_edge(i, ed, 1, -INF), MC.add_edge(i, ed, 200, 0);
            else MC.add_edge(st, i, 1, -INF), MC.add_edge(st, i, 200, 0);
        }
    }
    REP(i, 1, m){
        int a, b;
        cin >> a >> b;
        b += n1;
        MC.add_edge(a, b, 1, c[0], i);
        MC.add_edge(b, a, 1, c[1], i);
    }
    pii res = MC.Solve();
    res.SE += need * INF;
    if(res.SE >= INF){
        cout << -1 << endl;
        return 0;
    }
    int ans_cost = 0;
    REP(i, 0, MC.ecnt - 1) if(MC.e[i].id && MC.e[i].cp == 0){
        int color = (MC.e[i].u > MC.e[i].v);
        e_co[MC.e[i].id] = color;
        ans_cost += c[color];
    }
    cout << ans_cost << endl;
    REP(i, 1, m){
        if(e_co[i] == -1) printf("U");
        else if(e_co[i] == 0) printf("R");
        else printf("B");
    }
    cout << endl;
    return 0;
}
