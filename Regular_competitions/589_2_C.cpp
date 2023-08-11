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

ll x, n;

ll Q_pow(ll x, ll y){
    ll res = 1;
    while(y){
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

ll cal(ll b){
    ll sum = 0, v = b;
    while(1){
        sum += n / v;
        if(v >= n / b + 1) break;
        v *= b;
    }
    return Q_pow(b, sum);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> x >> n;
    ll ans = 1;
    for(ll k = 2; k * k <= x; ++k){
        if(x % k == 0){
            ans = ans * cal(k) % mod;
        }
        while(x % k == 0){
            x /= k;
        }
    }
    if(x > 1) ans = ans * cal(x) % mod;
    cout << ans << endl;
    return 0;
}
