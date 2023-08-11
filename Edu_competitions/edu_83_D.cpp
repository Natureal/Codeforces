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
const int mod = 998244353;

int fac[200010], two[200010];

const int maxn = 200010;

int inv[maxn];

int Q_pow(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

void Cal_inv(){
    fac[0] = 1;
    two[0] = 1;
    REP(i, 1, maxn - 1) fac[i] = 1LL * fac[i - 1] * i % mod, two[i] = 1LL * two[i - 1] * 2 % mod;
    inv[0] = 1;
    REP(i, 1, maxn - 1) inv[i] = Q_pow(fac[i], mod - 2);
}

ll Comb(int a, int b){
    ll res =  1LL * fac[a] * inv[b] % mod * inv[a - b] % mod;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    Cal_inv();
    int n, m;
    cin >> n >> m;
    if(n > m + 1) cout << 0 << '\n';
    else cout << 1LL * Comb(m, n - 1) * (n - 2) % mod * two[n - 3] % mod << '\n';
    return 0;
}
