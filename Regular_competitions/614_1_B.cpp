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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;

ll X0, Y0, ax, ay, bx, by, XS, YS, T;
ll X[61], Y[61];
ll tmax = 10000LL * 10000LL * 10000LL * 10000LL;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> X0 >> Y0 >> ax >> ay >> bx >> by >> XS >> YS >> T;
    X[1] = X0; Y[1] = Y0;
    int tot = 1, luck = 0;
    REP(i, 2, 58){
        X[i] = (X[i - 1] * ax + bx);
        Y[i] = (Y[i - 1] * ay + by);
        if(X[i] > 3 * tmax || Y[i] > 3 * tmax) break;
        tot = i;
    }
    REP(i, 1, tot){
        if(XS == X[i] && YS == Y[i]) luck = i;
    }
    int ans = 0;
    REP(i, 1, tot){
        ll dis = abs(X[i] - XS) + abs(Y[i] - YS);
        if(dis <= T){
            REP(j, i, tot){
                if(dis + abs(X[j] - X[i]) + abs(Y[j] - Y[i]) <= T){
                    ans = max(ans, j - i + 1 + (luck > 0 && (luck < i || luck > j)));
                }
            }
            DEC(j, i, 1){
                if(dis + abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= T){
                    ans = max(ans, i - j + 1 + (luck > 0 && (luck < j || luck > i)));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
