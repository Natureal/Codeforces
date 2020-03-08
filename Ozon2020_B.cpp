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

bool vis[100010];
char s[10010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> s + 1;
    int len = strlen(s + 1);
    vector<VI> ans;
    while(1){
        bool f = false;
        int p = len;
        VI tmp;
        REP(i, 1, len) if(vis[i] == false){
            if(s[i] == '('){
                while(p > i && (vis[p] || s[p] == '(')){
                    p--;
                }
                if(p <= i || vis[p] || s[p] == '('){
                    break;
                }
                tmp.PB(i);
                tmp.PB(p);
                vis[i] = vis[p] = true;
            }
        }
        if(SZ(tmp) == 0) break;
        sort(tmp.begin(), tmp.end());
        ans.PB(tmp);
    }
    cout << SZ(ans) << endl;
    REP(i, 0, SZ(ans) - 1){
        cout << SZ(ans[i]) << endl;
        for(auto v : ans[i]){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
