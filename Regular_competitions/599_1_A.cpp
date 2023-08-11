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
typedef pair<int,int> pii;
typedef vector<int> VI;
const int mod = 1000000007;

ll n;

ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    vector<ll> V;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            V.PB(i);
            V.PB(n / i);
        }
    }
    V.PB(n);
    ll ans = n;
    for(auto v: V){
        ans = gcd(ans, v);
    }
    cout << ans << endl;
    return 0;
}
