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

ll x, y, z;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> x >> y >> z;
    cout << (x + y) / z << " ";
    if((x + y) / z > x / z + y / z){
        cout << min(z - x % z, z - y % z) << endl;
    }
    else cout << 0 << endl;
    return 0;
}
