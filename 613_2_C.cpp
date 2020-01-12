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

ll X, TX;
ll ans;
VL g;
VI gt;

void Dfs(int p, ll v){
    if(p == SZ(g)){
        ans = min(ans, max(v, TX / v));
        return;
    }
    ll base = 1;
    REP(i, 1, gt[p]){
        base *= g[p];
    }
    Dfs(p + 1, v);
    Dfs(p + 1, v * base);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> X;
    TX = X;
    for(ll k = 2; k * k <= X; ++k){
        if(X % k == 0){
            g.PB(k);
            int num = 0;
            while(X % k == 0){
                num++;
                X /= k;
            }
            gt.PB(num);
        }
    }
    if(X > 1){
        g.PB(X);
        gt.PB(1);
    }
    ans = (1LL << 62) - 1;
    Dfs(0, 1);
    cout << ans << " " << TX / ans << endl;
    return 0;
}
