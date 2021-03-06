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

int n;
double a[100010];
int b[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    ll sum = 0;
    REP(i, 1, n){
        cin >> a[i];
        b[i] = (int)a[i];
        sum += b[i];
    }
    REP(i, 1, n){
        if(sum == 0) break;
        if(sum > 0 && a[i] < (double)b[i]){
            b[i]--;
            sum--;
        }
        else if(sum < 0 && a[i] > (double)b[i]){
            b[i]++;
            sum++;
        }
    }
    REP(i, 1, n){
        cout << b[i] << endl;
    }
    return 0;
}
