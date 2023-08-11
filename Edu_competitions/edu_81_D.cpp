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

int T;
ll a, m, ans;
VL fac;

ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}

void Dfs(int p, ll v, int num){
    if(p == SZ(fac)){
        if(num == 0) return;
        if(num & 1) ans -= (a + m - 1) / v - (a - 1) / v;
        else ans += (a + m - 1) / v - (a - 1) / v;
        return;
    }
    Dfs(p + 1, v, num);
    Dfs(p + 1, v * fac[p], num + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        fac.clear();
        cin >> a >> m;
        ll g = gcd(a, m);
        a /= g;
        m /= g;
        ll tm = m;
        for(ll i = 2; i * i <= m; ++i){
            if(tm % i == 0){
                fac.PB(i);
                while(tm % i == 0) tm /= i;
            }
        }
        if(tm > 1) fac.PB(tm);
        ans = m;
        Dfs(0, 1, 0);
        cout << ans << endl;
    }
    return 0;
}
