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

int n, I;
int a[400010];
map<int, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> I;
    REP(i, 1, n) cin >> a[i], mp[a[i]]++;
    sort(a + 1, a + n + 1);
    int m = unique(a + 1, a + n + 1) - a - 1;
    REP(i, 1, m){
        if(i > 1) mp[a[i]] += mp[a[i - 1]];
    }
    int topk = 8 * I / n;
    ll K = 1, k = 0;
    while(K < n && k < topk){
        K *= 2;
        k++;
    }
    int ans = n;
    REP(i, 1, m){
        int j = min(1LL * m, i + K - 1);
        int res = 0;
        if(i > 1) res += mp[a[i - 1]];
        if(j < m) res += mp[a[m]] - mp[a[j]];
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
