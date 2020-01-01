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
typedef vector<int> VI;
const int mod = 1000000007;

int n, m;
VI G[200010];
bool vis[200010];
int l, r;

void Dfs(int p,int pre){
    vis[p] = true;
    l = min(l, p);
    r = max(r, p);
    for(auto v: G[p]){
        if(vis[v]) continue;
        Dfs(v, p);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, m){
        int u, v;
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }
    vector<pii > V;
    REP(i, 1, n) if(!vis[i]){
        l = r = i;
        Dfs(i, -1);
        V.PB(MP(l, r));
    }
    sort(V.begin(), V.end());
    int ans = 0;
    REP(i, 0, SZ(V) - 1){
        if(i < SZ(V) - 1 && V[i + 1].FI <= V[i].SE){
            V[i + 1].SE = max(V[i + 1].SE, V[i].SE);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
