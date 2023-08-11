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

ll v[3], d;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> v[0] >> v[1] >> v[2] >> d;
    sort(v, v + 3);
    cout << max(0LL, d - (v[1] - v[0])) + max(0LL, d - (v[2] - v[1])) << endl;
    return 0;
}
