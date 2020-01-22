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

int n, sz[200010];
VI G[200010];
ll dp[200010];
ll ans;

void Dfs(int p, int pre){
    sz[p] = 1;
    dp[p] = 0;
    for(auto v: G[p]) if(v != pre){
        Dfs(v, p);
        sz[p] += sz[v];
        dp[p] += dp[v];
    }
    dp[p] += sz[p];
}

void Solve(int p, int pre, ll cur){
    ans = max(ans, cur);
    ll sum = 0;
    for(auto v: G[p]) if(v != pre){
        sum += dp[v];
    }
    for(auto v: G[p]) if(v != pre){
        Solve(v, p, cur + sum - dp[v] + n - sz[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n - 1){
        int a, b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    Dfs(1, -1);
    Solve(1, -1, n);
    cout << ans << endl;
    return 0;
}
