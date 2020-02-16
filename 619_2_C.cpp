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

int t;
ll n, m;

ll Cal(ll a){
    return a * (a - 1) / 2 + a;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> m;
        ll S = n * (n - 1) / 2 + n;
        ll rem = n - m;
        ll k = rem / (m + 1), r = rem % (m + 1);
        cout << S - Cal(k) * (m + 1 - r) - Cal(k + 1) * r << endl;
    }
    return 0;
}
