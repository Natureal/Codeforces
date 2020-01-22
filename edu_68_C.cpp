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

int q, num[26];
string s, t, p;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> q;
    REP(T, 1, q){
        cin >> s >> t >> p;
        MEM(num, 0);
        REP(i, 0, p.length()  - 1) num[p[i] - 'a']++;
        if(s.length() > t.length()){
            cout << "NO" << endl;
            continue;
        }
        int pos = 0;
        bool f = true;
        REP(i, 0, t.length() - 1){
            if(pos >= s.length() || t[i] != s[pos]){
                if(num[t[i] - 'a'] == 0){
                    f = false;
                    break;
                }
                num[t[i] - 'a']--;
            }
            else{
                pos++;
            }
        }
        if(pos != s.length()) f = false;
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
