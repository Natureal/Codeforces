#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define DEC(i, a, b) for(int i = b; i >= a; --i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define SZ(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1000000007;

int n;
vector<int> G[500010];
pii ans[500010];
int dg[500010];

int Dfs(int ed, int p, int pre){
    int new_ed = ed;
    int num = 0;
    REP(i, 0, SZ(G[p]) - 1){
        int v = G[p][i];
        if(v == pre) continue;
        num++;
        ans[v] = MP(new_ed - num, ed + dg[v]);
        ed = Dfs(ed + dg[v], v, p);
    }
    return ed;
}

int main(){
	scanf("%d", &n);
    REP(i, 1, n - 1){
        int a, b;
        scanf("%d %d", &a, &b);
        dg[a]++;
        dg[b]++;
        G[a].PB(b);
        G[b].PB(a);
    }
    ans[1] = MP(1, dg[1] + 2);
    Dfs(dg[1] + 2, 1, -1);
    REP(i, 1, n){
        printf("%d %d\n", ans[i].FI, ans[i].SE);
    }
    return 0;
}
