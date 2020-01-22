#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): *(s.find_by_order(2), counting from 0)
// order_of_key(k) returns the number of items strictly smaller than item k.
template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, 
        tree_order_statistics_node_update>;

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

int n, m, q;
int dif_ori;
int D[1010][1010];
char g[1010][1010];

ll Cal(int f, ll x, ll y){
    return (f ? -1 : 1) * D[x][y];
}

ll Solve(ll x, ll y){
    if(x == 0 || y == 0) return 0;
    x--; y--; // 0-based index
    ll dif = 0, a = x / n, b = y / m;
    int ap = __builtin_popcount(a) & 1;
    int bp = __builtin_popcount(b) & 1;
    int f = ap ^ bp;
    dif += Cal(f, x % n, y % m);
    if(a % 2){
        // even rows
        dif += Cal(f ^ 1, n - 1, y % m);
    }
    if(b % 2){
        // even columns
        dif += Cal(f ^ 1, x % n, m - 1);
    }
    if(a % 2 && b % 2) dif += Cal(f, n - 1, m - 1);
    return ((x + 1) * (y + 1) + dif) / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    REP(i, 0, n - 1) cin >> g[i];
    REP(i, 0, n - 1){
        REP(j, 0, m - 1){
            D[i][j] = (g[i][j] == '1') ? 1 : -1;
            if(i > 0) D[i][j] += D[i - 1][j];
            if(j > 0) D[i][j] += D[i][j - 1];
            if(i > 0 && j > 0) D[i][j] -= D[i - 1][j - 1];
        }
    }
    dif_ori = D[n - 1][m - 1];
    REP(i, 1, q){
        ll X[2], Y[2];
        cin >> X[0] >> Y[0] >> X[1] >> Y[1];
        cout << Solve(X[1], Y[1]) - Solve(X[1], Y[0] - 1) - Solve(X[0] - 1, Y[1]) + 
            Solve(X[0] - 1, Y[0] - 1) << endl;
    }

    return 0;
}
