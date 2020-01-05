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
int mod = 1000000007;

int A[300010];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> mod;
    A[0] = 1;
	A[1] = 1;
    REP(i, 2, n){
        A[i] = 1LL * i * A[i - 1] % mod;
    }
    int ans = 0;
    REP(i, 1, n){
        int tmp = 1LL * (n - i + 1) * (n - i + 1) % mod * A[i] % mod * A[n - i] % mod;
        ans = (ans + tmp) % mod;
    }
    cout << ans << endl;
    return 0;
}
