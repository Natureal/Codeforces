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

int n, tot;
int ans[1000010], A[1000010], val[1000010];
VPI G[1000010];

void Go(int p, int num){
    ans[p] = (ans[p] == -1 ? num : min(ans[p], num));
    if(SZ(G[p])){
        Go(G[p][0].SE, ans[p] + val[p]);
    }
}

void Dfs(int p, int num){
    ans[p] = (ans[p] == -1 ? num : min(ans[p], num));
    if(SZ(G[p])){
        Go(G[p][0].SE, ans[p] + 1 + val[p]);
        REP(i, 0, SZ(G[p]) - 1){
            Dfs(G[p][i].SE, ans[p] + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    int tmax = 0;
    REP(i, 1, n){
        int p;
        char s[2];
        cin >> p >> s;
        G[p].PB(MP(s[0] - 'a', i));
        tmax = max(tmax, p);
    }
    REP(i, 0, tmax) sort(G[i].begin(), G[i].end());
    MEM(ans, -1);
    int K;
    cin >> K;
    REP(i, 1, K){
        cin >> A[i];
        val[A[i]] = 1;
    }
    Dfs(0, 0);
    REP(i, 1, K){
        cout << ans[A[i]] << " ";
    }
    cout << '\n';
    return 0;
}
