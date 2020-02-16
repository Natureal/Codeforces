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

int t, n;
char s[200010];
int ans[200010], ans2[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> s + 1;
        MEM(ans, 0);
        MEM(ans2, 0);
        int tot = 0;
        REP(i, 1, n - 1){
            int j = i;
            while(j + 1 <= n - 1 && s[j + 1] == s[i]) j++;
            if(s[i] == '>'){
                DEC(k, j, i) ans[k + 1] = ++tot;
                if(i == 1) ans[1] = ++tot;
            }
            i = j;
        }
        int tot2 = tot, tn = n;
        REP(i, 1, n) if(ans[i] == 0) ans[i] = ++tot;
        REP(i, 1, n - 1){
            int j = i;
            while(j + 1 <= n - 1 && s[j + 1] == s[i]) j++;
            if(s[i] == '>'){
                if(i == 1) ans2[1] = tot2--;
                REP(k, i, j) ans2[k + 1] = tot2--;
            }
            else{
                DEC(k, j, i) ans2[k + 1] = tn--;
                if(i == 1) ans2[1] = tn--;
            }
            i = j;
        }
        REP(i, 1, n) cout << ans2[i] << " ";
        cout << endl;
        REP(i, 1, n) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
