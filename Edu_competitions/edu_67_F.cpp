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

int Q_pow(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

int n, l[200010], r[200010], p[200010];

ll Cal2(ll a, ll b){
    ll L = min(r[a], r[b]) - max(l[a], l[b]) + 1;
    ll L1 = r[a] - l[a] + 1, L2 = r[b] - l[b] + 1;
    if(L < 0) L = 0;
    ll p = 1LL * L * Q_pow(1LL * L1 * L2 % mod, mod - 2) % mod;
    return p;
}

ll Cal3(ll a, ll b, ll c){
    ll L = min(r[a], min(r[b], r[c])) - max(l[a], max(l[b], l[c])) + 1;
    ll L1 = r[a] - l[a] + 1, L2 = r[b] - l[b] + 1, L3 = r[c] - l[c] + 1;
    if(L < 0) L = 0;
    ll p = 1LL * L * Q_pow(1LL * L1 * L2 % mod * L3 % mod, mod - 2) % mod;
    return p;
}

ll Solve(ll a, ll b){
    ll p = ((1 - Cal2(a, b)) % mod - Cal2(b, b + 1)) % mod;
    p = (p + Cal3(a, b, b + 1)) % mod;
    p = (p + mod) % mod;
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> l[i];
    REP(i, 1, n) cin >> r[i];
    l[n + 1] = r[n + 1] = 1e9 + 1;
    ll sum = 0;
    REP(i, 1, n){
        p[i] = (1 - Cal2(i, i + 1) + mod) % mod;
        sum = (sum + p[i]) % mod;
    }
    ll ans = 0;
    REP(i, 1, n){
        ll tsum = (sum - p[i]) % mod;
        if(i > 1) tsum = (tsum - p[i - 1] + mod) % mod;
        if(i < n) tsum = (tsum - p[i + 1] + mod) % mod;
        ans = (ans + tsum * p[i] % mod + p[i]) % mod;
        if(i > 1) ans = (ans + Solve(i - 1, i)) % mod;
        if(i < n) ans = (ans + Solve(i, i + 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}
