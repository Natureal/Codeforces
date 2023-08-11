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

int Q_pow(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

int n, k[1000010];
vector<int> G[1000010];
int num[1000010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> k[i];
        REP(j, 1, k[i]){
            int a;
            cin >> a;
            G[i].PB(a);
            num[a]++;
        }
    }
    int ans = 0, base = 0;
    int inv_n = Q_pow(n, mod - 2), inv_n_2 = Q_pow(1LL * n * n % mod, mod - 2);
    REP(i, 1, n){
        int inv_k = Q_pow(k[i], mod - 2);
        for(auto v: G[i]) if(num[v] >= 1){
            ans = (ans + 1LL * inv_n_2 * inv_k % mod * num[v] % mod) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
