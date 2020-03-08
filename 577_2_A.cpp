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

int n, m;
string s[1010];
int num[1010][5];
int a[1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, 1, n){
        cin >> s[i];
        REP(j, 0, m - 1) num[j][s[i][j] - 'A'] += 1;
    }
    REP(i, 1, m) cin >> a[i];
    ll ans = 0;
    REP(i, 0, m - 1){
        int tmax = 0;
        REP(j, 0, 4){
            tmax = max(tmax, num[i][j] * a[i + 1]);
        }
        ans += tmax;
    }
    cout << ans << endl;
    return 0;
}
