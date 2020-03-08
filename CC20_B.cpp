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

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        string s;
        cin >> s;
        int ans = 1;
        string ans_str = s;
        REP(i, 2, n){
            string tmp = s.substr(i - 1, n - i + 1);
            string tmp2 = s.substr(0, i - 1);
            if((n - i + 1) & 1){
                reverse(tmp2.begin(), tmp2.end());
            }
            tmp += tmp2;
            if(tmp < ans_str){
                ans_str = tmp;
                ans = i;
            }
        }
        cout << ans_str << endl;
        cout << ans << endl;
    }
    return 0;
}
