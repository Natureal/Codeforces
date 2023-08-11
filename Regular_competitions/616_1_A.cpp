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

int t, n, m, k;
int a[3510], b[3510];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> m >> k;
        REP(i, 1, n) cin >> a[i];
        k = min(k, m - 1);
        int N = m - k, L = n - m + 1;
        REP(i, 1, n - L + 1){
            b[i] = max(a[i], a[i + L - 1]);
        }
        int ans = 0;
        REP(i, 1, n){
            if(i + N - 1 > n - L + 1) break;
            int tmin = 1e9 + 1;
            REP(j, i, i + N - 1) tmin = min(tmin, b[j]);
            ans = max(ans, tmin);
        }
        cout << ans << endl;
    }
    return 0;
}
