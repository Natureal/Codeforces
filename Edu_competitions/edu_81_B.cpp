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

int T, n, x;
char s[100010];
int pre[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> n >> x;
        cin >> s + 1;
        bool f = false;
        REP(i, 1, n){
            pre[i] = pre[i - 1];
            if(s[i] == '0') pre[i]++;
            else pre[i]--;
            if(pre[i] == x) f = true;
        }
        if(pre[n] == 0 && f) cout << -1 << endl;
        else{
            int ans = (x == 0);
            REP(i, 1, n){
                if(pre[n] == 0){
                    if(pre[i] == x) ans++;
                }
                else{
                    if(x > pre[i] && pre[n] < 0) continue;
                    if(x < pre[i] && pre[n] > 0) continue;
                    if((x - pre[i]) % pre[n] == 0) ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
