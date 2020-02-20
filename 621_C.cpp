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

char s[100010];
ll num[26];
ll sum[26][26];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> s + 1;
    int len = strlen(s + 1);
    DEC(i, len, 1){
        REP(j, 0, 25){
            sum[s[i] - 'a'][j] += num[j];
        }
        num[s[i] - 'a'] += 1;
    }
    ll ans = 0;
    REP(i, 0, 25) ans = max(ans, num[i]);
    REP(i, 0, 25){
        REP(j, 0, 25){
            ans = max(ans, sum[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
