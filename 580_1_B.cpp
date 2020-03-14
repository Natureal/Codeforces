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
 
int n, ans, edge;
ll A[100010];
VI pw[63], G[100010];
int vis[100010];
 
void Dfs(int p, int pre, int num, int st){
    if(num > edge + 1 || num > ans) return;
    vis[p] = 1;
    for(auto v: G[p]) if(v != pre){
        if(vis[v] && v == st){
            ans = min(ans, num);
        }
        if(!vis[v]) Dfs(v, p, num + 1, st);
    }
    vis[p] = 0;
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    REP(i, 1, n){
        cin >> A[i];
        REP(j, 0, 62) if(A[i] & (1LL << j)){
            pw[j].PB(i);
        }
    }
    bool f = false;
    REP(i, 0, 62) if(SZ(pw[i]) > 2){
        f = true;
        break;
    }
    if(f){
        cout << 3 << endl;
        return 0;
    }
    REP(i, 0, 62) if(SZ(pw[i]) == 2){
        int a = pw[i][0], b = pw[i][1];
        G[a].PB(b);
        G[b].PB(a);
        edge++;
    }
    ans = (1 << 30);
    REP(i, 1, n){
        Dfs(i, -1, 1, i);
    }
    cout << (ans == (1 << 30) ? -1 : ans) << endl;
    return 0;
}
