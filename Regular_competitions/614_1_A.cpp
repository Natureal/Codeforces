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

int n, q;
int s[3][100010], v[3][100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> q;
    int sum = 0;
    REP(i, 1, q){
        int r, c;
        cin >> r >> c;
        if(s[r][c] == 0){
            s[r][c] = 1;
            int tr = (r == 1) ? 2 : 1;
            v[r][c] = s[tr][c - 1] + s[tr][c] + s[tr][c + 1];
            if(s[tr][c - 1]){
                v[tr][c - 1]++; sum++;
            }
            if(s[tr][c]){
                v[tr][c]++; sum++;
            }
            if(s[tr][c + 1]){
                v[tr][c + 1]++; sum++;
            }
        }
        else{
            s[r][c] = 0;
            int tr = (r == 1) ? 2 : 1;
            v[r][c] = 0;
            if(s[tr][c - 1]){
                v[tr][c - 1]--; sum--;
            }
            if(s[tr][c]){
                v[tr][c]--; sum--;
            }
            if(s[tr][c + 1]){
                v[tr][c + 1]--; sum--;
            }
        }
        if(sum == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
