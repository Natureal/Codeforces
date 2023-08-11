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

int T;
string s, s2;
int pos[30];
char ans[70];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> s;
        MEM(pos, -1);
        MEM(ans, 0);
        int p = 35;
        pos[s[0] - 'a'] = p;
        ans[p] = s[0];
        bool f = true;
        REP(i, 1, SZ(s) - 1){
            if(pos[s[i] - 'a'] == -1){
                if(ans[p - 1] == 0){
                    p--;
                    pos[s[i] - 'a'] = p;
                    ans[p] = s[i];
                }
                else if(ans[p + 1] == 0){
                    p++;
                    pos[s[i] - 'a'] = p;
                    ans[p] = s[i];
                }
                else{
                    f = false;
                    break;
                }
            }
            else{
                if(ans[p - 1] == s[i]){
                    p--;
                }
                else if(ans[p + 1] == s[i]){
                    p++;
                }
                else{
                    f = false;
                    break;
                }
            }
        }
        if(!f){
            cout << "NO" << endl;
            continue;
        }
        int st = -1, ed = -1;
        REP(i, 0, 69){
            if(ans[i] && st == -1) st = i;
            if(ans[i]) ed = i;
        }
        REP(i, 0, 25) if(pos[i] == -1){
            ans[++ed] = i + 'a';
        }
        cout << "YES" << endl;
        cout << ans + st  << endl;
    }
    return 0;
}
