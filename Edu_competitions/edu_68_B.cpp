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

int q, n, m;
string s[50010];
int nr[50010], nc[50010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> q;
    REP(t, 1, q){
        cin >> n >> m;
        MEM(nr, 0);
        MEM(nc, 0);
        REP(i, 0, n - 1){
            cin >> s[i];
            REP(j, 0, m - 1) if(s[i][j] == '.'){
                nr[i]++;
                nc[j]++;
            }
        }
        int ans = 1e9;
        REP(i, 0, n - 1){
            REP(j, 0, m - 1){
                ans = min(ans, nr[i] + nc[j] - (s[i][j] == '.'));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
