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

int t, n, m, a, b;
int vis[200010];
vector<int> G[200010];
int sz1, sz2;
int f, sz;

void Dfs(int p, int tar){
	if(p == tar){
		f = 1;
		return;
	}
	if(vis[p]) return;
	vis[p] = 1;
	sz++;
	for(int i = 0; i < G[p].size(); ++i){
		Dfs(G[p][i], tar);
	}
}

int main(){
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> n >> m >> a >> b;
		for(int j = 1; j <= n; ++j) G[j].clear();
		for(int j = 1; j <= m; ++j){
			int v1, v2;
			cin >> v1 >> v2;
			G[v1].PB(v2);
			G[v2].PB(v1);
		}
		sz1 = sz2 = 0;
		// for a
		memset(vis, 0, sizeof(vis));
		vis[a] = 1;
		for(int j = 0; j < G[a].size(); ++j){
			f = sz = 0;
			Dfs(G[a][j], b);
			if(!f) sz1 += sz;
		}
		memset(vis, 0, sizeof(vis));
		vis[b] = 1;
		for(int j = 0; j < G[b].size(); ++j){
			f = sz = 0;
			Dfs(G[b][j], a);
			if(!f) sz2 += sz;
		}
		cout << 1LL * sz1 * sz2 << endl;
	}
	return 0;
}
