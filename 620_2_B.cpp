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
string s[110], rs[110];
int vis[110], judge[110];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(), rs[i].end());
        if(s[i] == rs[i]) judge[i] = 1;
    }
    int tot = 0;
    string ans = "";
    REP(i, 1, n) if(vis[i] == 0){
        REP(j, i + 1, n) if(vis[j] == 0){
            if(s[i] == rs[j]){
                vis[i] = vis[j] = ++tot;
                ans += s[i];
                break;
            }
        }
    }
    string r_ans = ans;
    reverse(r_ans.begin(), r_ans.end());
    REP(i, 1, n) if(vis[i] == 0 && judge[i] == 1){
        ans += s[i];
        break;
    }
    ans += r_ans;
    cout << SZ(ans) << endl;
    cout << ans << endl;
    return 0;
}
