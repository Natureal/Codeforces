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

int main(){
    ios_base::sync_with_stdio(false);
	int t;
    string s;
    cin >> t;
    REP(q, 1, t){
        cin >> s;
        int num = 0, f = 1000, f2 = 0;
        REP(i, 0, SZ(s) - 1){
            if(s[i] == '1'){
                if(f == 1000) f = i;
                f2 = i;
            }
        }
        REP(i, f, f2){
            num += (s[i] == '0');
        }
        cout << num << endl;
    }
    return 0;
}
