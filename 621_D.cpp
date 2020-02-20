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
const int INF = (1 << 30);
const int maxn = 200010;

int k;
int A[200010];

int N,M;
int first[maxn],nxt[4 * maxn],ver[4 * maxn],ecnt;
int dis[maxn], dis2[maxn];

struct edge{
    int v,cost;
    friend bool operator < (edge a,edge b){
        return a.cost > b.cost;
    }
}e[4 * maxn];

void Add_edge(int u,int v,int c){
    nxt[++ecnt] = first[u];
    e[ecnt].v = v;
    e[ecnt].cost = c;
    first[u] = ecnt;
}

struct cmp{
    bool operator ()(pii a,pii b){
        return a.first > b.first;
    }
};

int Dijstra(int s){
    priority_queue<pii,vector<pii >,cmp> PQ;
    fill(dis + 1,dis + N + 1,INF);
    dis[s] = 0;
    PQ.push(MP(dis[s],s));
    int cnt = 0;
    while(!PQ.empty()){
        pii x = PQ.top(); PQ.pop();
        if(dis[x.second] < x.first) continue; //当前的x并非最短路径，舍弃
        for(int i = first[x.second]; i != -1; i = nxt[i]){
            int v = e[i].v;
            if(dis[v] > dis[x.second] + e[i].cost){
                dis[v] = dis[x.second] + e[i].cost;
                PQ.push(MP(dis[v],v));
            }
        }
    }
    return dis[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    MEM(first, -1);
    ecnt = 0;
	cin >> N >> M >> k;
    REP(i, 1, k){
        int a;
        cin >> a;
        A[a] = 1;
    }
    REP(i, 1, M){
        int a, b;
        cin >> a >> b;
        Add_edge(a, b, 1);
        Add_edge(b, a, 1);
    }
    Dijstra(1);
    REP(i, 1, N) dis2[i] = dis[i];
    Dijstra(N);
    VPI V2, V;
    REP(i, 1, N) if(A[i]){
        V.PB(MP(dis[i], i));
        V2.PB(MP(dis2[i], i));
    }
    sort(V.begin(), V.end());
    sort(V2.begin(), V2.end());
    int tmax = 0;
    REP(i, 0, SZ(V2) - 2){
        tmax = max(tmax, V2[i].FI + 1 + dis[V2[i + 1].SE]);
    }
    cout << min(tmax, dis2[N]) << endl;
    return 0;
}
