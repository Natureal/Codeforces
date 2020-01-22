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

int main(){
    ios_base::sync_with_stdio(false);
	int T, n, k;
    cin >> T;
    while(T--){
        cin >> n >> k;
        if(k % 3 != 0){
            cout << (n % 3 == 0 ? "Bob" : "Alice") << endl;
            continue;
        }
        n %= (k + 1);
        if(n == k || n % 3 != 0){
            cout << "Alice" << endl;
        }
        else cout << "Bob" << endl;
    }
    return 0;
}
