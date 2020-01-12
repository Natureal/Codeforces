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
const int mod = 1000000007;

int n;
char s[2][1000010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(q, 1, n){
        cin >> s[0] >> s[1];
        int len0 = strlen(s[0]), len1 = strlen(s[1]);
        bool f = (len0 <= len1);
        if(f){
            int p1 = 0;
            REP(i, 0, len0 - 1){
                if(p1 >= len1 || s[0][i] != s[1][p1]){
                    f = false;
                    break;
                }
                int ti = i;
                while(ti + 1 < len0 && s[0][ti + 1] == s[0][i]) ti++;
                int tp1 = p1;
                while(tp1 + 1 < len1 && s[1][tp1 + 1] == s[1][p1]) tp1++;
                if(p1 >= len1 || ti - i + 1 > tp1 - p1 + 1){
                    f = false;
                    break;
                }
                i = ti;
                p1 = tp1 + 1;
            }
            if(p1 < len1) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
