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

int t, k;
vector<pii> g[200010];
ll G, B;
int sz[200010];

int Dfs(int p, int pre){
    sz[p] = 1;
    int num = 0;
    for(int i = 0; i < g[p].size(); ++i){
        int v = g[p][i].first;
        int w = g[p][i].second;
        if(v == pre) continue;
        if(Dfs(v, p)){
            G += w;
            num++;
        }
        sz[p] += sz[v];
        B += 1LL * min(2 * k - sz[v], sz[v]) * w;
    }
    return num % 2 == 0;
}

int main(){
	cin >> t;
    for(int q = 1; q <= t; ++q){
        cin >> k;
        G = B = 0;
        for(int i = 1; i <= 2 * k; ++i) g[i].clear();
        for(int i = 1; i < 2 * k; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            if(a > b) swap(a, b);
            g[a].PB(MP(b, c));
            g[b].PB(MP(a, c));
        }
        Dfs(1, 0);
        cout << G << " " <<  B << endl;
    }
    
    return 0;
}
