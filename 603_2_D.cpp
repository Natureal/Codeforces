// DSU
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

int n;
int fa[200010];
vector<int> G[26];

int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x != y){
        fa[x] = y;
    }
}

int main(){
	cin >> n;
    for(int i = 1; i <= n; ++i){
        string a;
        cin >> a;
        fa[i] = i;
        bool vis[26] = {0};
        for(int j = 0; j < a.length(); ++j){
            vis[a[j] - 'a'] = true;
        }
        for(int j = 0; j < 26; ++j) if(vis[j]){
            G[j].PB(i);
        }
    }
    for(int i = 0; i < 26; ++i){
        for(int j = 1; j < G[i].size(); ++j){
            Union(G[i][0], G[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) if(fa[i] == i) ans++;
    cout << ans << endl;
    return 0;
}
