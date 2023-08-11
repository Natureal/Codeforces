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

int n;
int X[100010], Y[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> X[i] >> Y[i];
    }
    if(n % 2){
        cout << "NO" << endl;
        return 0;
    }
    bool f = true;
    REP(i, 1, n / 2){
        int j1 = i + n / 2, j2 = j1 + 1;
        if(j2 > n) j2 = 1;
        if(X[i + 1] - X[i] != X[j1] - X[j2]) f = false;
        if(Y[i + 1] - Y[i] != Y[j1] - Y[j2]) f = false;
        if(!f) break;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
