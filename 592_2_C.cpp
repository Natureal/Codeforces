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

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

ll n, p, w, d;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> p >> w >> d;
    ll lcm = w / gcd(w, d) * d;
    ll x = -1, y = -1;
    DEC(i, lcm / d, 0){
        if(p >= i * d && (p - i * d) % w == 0){
            x = (p - i * d) / w;
            y = i;
            if(x + y > n) x = -1;
            else break;
        }
    }
    if(x == -1) cout << -1 << endl;
    else cout << x << " " << y << " " << n - x - y << endl;
    return 0;
}
