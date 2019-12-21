// Math, binomial k-th moment 
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
const int mod = 998244353;

int n, m , k;
int f[5010], c[5010][5010];

int Q_pow(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    int inv_m = Q_pow(m, mod - 2), ans = 0;
    f[0] = 1;
    REP(i, 1, k){
        f[i] = 1LL * f[i - 1] * (n - i + 1) % mod * inv_m % mod;
    }
    c[1][1] = 1;
    REP(i, 1, k - 1){
        REP(j, 1, i){
            c[i + 1][j] = (c[i + 1][j] + 1LL * c[i][j] * j % mod) % mod;
            c[i + 1][j + 1] = (c[i + 1][j + 1] + c[i][j]) % mod; 
        }
    }
    REP(i, 1, k){
        ans = (ans + 1LL * c[k][i] * f[i] % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}

