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
const int mod = 1000000007;

int n, tot, P[2010], C[2010], A[2010], sz[2010];
VI G[2010], ST;

bool Dfs(int p, int pre){
    sz[p] = 1;
    for(auto v: G[p]){
        if(v == pre) continue;
        if(!Dfs(v, p)){
            return false;
        }
        sz[p] += sz[v];
    }
    if(C[p] > sz[p] - 1) return false;
    ST.insert(ST.begin() + C[p], p);
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int root;
    REP(i, 1, n){
        cin >> P[i] >> C[i];
        if(P[i] == 0) root = i;
        else{
            G[P[i]].PB(i);
        }
    }
    if(!Dfs(root, -1)) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(auto v: ST){
            A[v] = ++tot;
        }
        REP(i, 1, n) cout << A[i] << " ";
        cout << endl;
    }
    return 0;
}
