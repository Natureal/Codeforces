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
const int mod = 1000000007;

int N, T, A;
vector<int> G[100010];
int da[100010], son[100010];
int ans;

void Dfs(int p, int pre, int len, int d[]){
    d[p] = len;
    REP(i, 0, SZ(G[p]) - 1){
        int v = G[p][i];
        if(v == pre) continue;
        Dfs(v, p, len + 1, d);
        son[p] = 1;
    }
}

void Dfs2(int p, int pre, int len){
    //cout << "p : " << p << endl;
    if(len > da[p]) return;
    REP(i, 0, SZ(G[p]) - 1){
        int v = G[p][i];
        if(v == pre) continue;
        Dfs2(v, p, len + 1);
    }
    if(son[p]) ans = max(ans, da[p]);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> N >> T >> A;
    REP(i, 1, N - 1){
        int a, b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    Dfs(A, -1, 0, da);
    Dfs2(T, -1, 0);
    cout << ans << endl;
    return 0;
}
