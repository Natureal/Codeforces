// Randomizaton
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

int n;
ll A[200010];

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

ll Test(ll v){
    ll res = 0;
    REP(i, 1, n) if(A[i] % v != 0){
        ll k = A[i] / v;
        if(k == 0) res += v - A[i];
        else res += min(A[i] - k * v, (k + 1) * v - A[i]);
    }
    return res;
}

mt19937_64 rng_ll(chrono::steady_clock::now().time_since_epoch().count());

ll rand_ll(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng_ll);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> A[i];
    }
    ll G = A[1];
    REP(i, 2, n){
        G = gcd(G, A[i]);
    }
    if(G > 1) cout << 0 << endl;
    else{
        ll ans = n;
        REP(i, 1, 20){
            int id = rand_ll(1, n);
            REP(j, -1, 1){
                ll cur = A[id] + j;
                if(cur > 1){
                    for(ll k = 2; k * k <= A[id] + j; ++k){
                        if(cur % k == 0){
                            ans = min(ans, Test(k));
                            while(cur % k == 0) cur /= k;
                        }
                    }
                    if(cur > 1) ans = min(ans, Test(cur));
                }
            }   
        }
        cout << ans << endl;
    }
    return 0;
}
