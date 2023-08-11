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
pii tmax[1 << 8];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    for(int s = 0; s < (1 << m); ++s) tmax[s].FI = -1;
    REP(i, 1, n){
        int a[10];
        REP(j, 0, m - 1){
            cin >> a[j];
        }
        for(int s = 0; s < (1 << m); ++s){
            int tmin = 1e9 + 1;
            for(int k = 0; k < m; ++k) if(s & (1 << k)){
                tmin = min(tmin, a[k]);
            }
            if(tmin > tmax[s].FI){
                tmax[s] = MP(tmin, i);
            }
        }
    }
    int ans = -1;
    pii ans_p;
    int full = (1 << m) - 1;
    for(int s = 0; s < (1 << m); ++s){
        if(min(tmax[s].FI, tmax[full ^ s].FI) > ans){
            ans = min(tmax[s].FI, tmax[full ^ s].FI);
            ans_p = MP(tmax[s].SE, tmax[full ^ s].SE);
        }
    }
    cout << ans_p.FI << " " << ans_p.SE << endl;
    return 0;
}
