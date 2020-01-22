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
int t[1010], l[1010], r[1010], vis[1010];
int ans[1010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, m){
        cin >> t[i] >> l[i] >> r[i];
    }
    bool f = true;
    ans[1] = 1e6;
    REP(i, 2, n){
        bool b[2] = {0, 0};
        REP(j, 1, m) if(!vis[j]){
            if(r[j] >= i && l[j] < i){
                b[t[j]] = true;
            }
        }
        if(b[1]){
            ans[i] = ans[i - 1];
        }
        else if(b[0]){
            ans[i] = ans[i - 1] - 1;
            REP(j, 1, m) if(!vis[j] && t[j] == 0){
                if(r[j] >= i && l[j] < i){
                    vis[j] = 1;
                }
            }
        }
        else{
            ans[i] = ans[i - 1];
        }
    }
    REP(i, 1, m) if(t[i] == 0 && !vis[i]) f = false;
    if(f){
        cout << "YES" << endl;
        REP(i, 1, n) cout << ans[i] << " ";
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
