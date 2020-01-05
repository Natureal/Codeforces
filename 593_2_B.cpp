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
	int n, m;
    cin >> n >> m;
    int v = Q_pow(2, m) - 1;
    if(v < 0) v += mod;
    cout << Q_pow(v, n) << endl;
    return 0;
}
