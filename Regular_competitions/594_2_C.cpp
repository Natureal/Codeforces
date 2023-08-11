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
typedef vector<int> VI;
const int mod = 1000000007;

int n, m;
int f[100010], d[100010];

int main(){
    ios_base::sync_with_stdio(false);
	f[1] = 2;
    f[2] = 6;
    d[1] = 0;
    d[2] = 2;
    REP(i, 3, 100000){
        f[i] = (f[i - 1] + f[i - 2] + 2) % mod;
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    }
    cin >> n >> m;
    if(n > m) swap(n, m);
    int ans = f[m];
    while(n < m){
        ans = ((ans - d[m]) % mod + mod) % mod;
        m--;
    }
    cout << ans << endl;
    return 0;
}
