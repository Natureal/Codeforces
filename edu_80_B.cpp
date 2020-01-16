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

int main(){
    ios_base::sync_with_stdio(false);
    REP(i, 1, 100){
        REP(j, 1, 100){
            int a = i * j + i + j;
            int b = 10;
            if(i >= 10) b *= 10;
            if(i >= 100) b *= 10;
            //if(a == i * b + j) printf("%d %d , %d\n", i, j, a);
        }
    }
    int t, A, B;
    cin >> t;
    REP(q, 1, t){
        cin >> A >> B;
        ll num = 0, base = 9;
        while(B >= base){
            num++;
            base = base * 10 + 9;
        }
        cout << A * num << endl;
    }
    return 0;
}
