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

int n, m;
int g[1010][1010];
ordered_set<int> ost_r[1010], ost_c[1010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        REP(j, 1, m){
            cin >> g[i][j];
            ost_r[i].insert(g[i][j]);
            ost_c[j].insert(g[i][j]);
        }
    }
    REP(i, 1, n){
        REP(j, 1, m){
            int sr = ost_r[i].order_of_key(g[i][j]);
            int br = ost_r[i].size() - sr - 1;
            int sc = ost_c[j].order_of_key(g[i][j]);
            int bc = ost_c[j].size() - sc - 1;
            cout << max(sr, sc) + 1 + max(br, bc) << " ";
        }
        cout << endl;
    }
    return 0;
}
