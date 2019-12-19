// Expection DP
#include <bits/stdc++.h>
using namespace std;
 
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;
const int mod = 998244353;

int n, p[200010], mp[200010];

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
	cin >> n;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        p[i] = 1LL * a * Q_pow(100, mod - 2) % mod;
        mp[i] = 1LL * (100 - a) * Q_pow(100, mod - 2) % mod;
    }
    int H = 1, base = 1;
    for(int i = 1; i < n; ++i){
        base = 1LL * base * p[i] % mod;
        H = (H + base) % mod;
    }
    int G = 0, pre = 1;
    for(int i = 1; i <= n; ++i){
        G = (G + 1LL * pre * mp[i]) % mod;
        pre = 1LL * pre * p[i] % mod;
    }
    int ans = 1LL * H * Q_pow((1 - G + mod) % mod, mod - 2) % mod;
    cout << ans << endl;
    return 0;
}
