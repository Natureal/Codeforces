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
typedef pair<int,int> pii;
typedef vector<int> VI;
const int mod = 1000000007;

char s[100010];
int ff[100010];

int main(){
    ios_base::sync_with_stdio(false);
    ff[1] = 1;
    ff[2] = 2;
    ff[3] = 3;
    REP(i, 4, 100000) ff[i] = (ff[i - 1] + ff[i - 2]) % mod;
	cin >> s + 1;
    int len = strlen(s + 1);
    int ans = 1;
    bool f = true;
    REP(i, 1, len){
        if(s[i] == 'w' || s[i] == 'm'){
            f = false;
            break;
        }
        if(s[i] == 'u' || s[i] == 'n'){
            int j = i;
            while(j + 1 <= len && s[j + 1] == s[i]) j++;
            if(j > i){
                ans = 1LL * ans * (ff[j - i + 1]) % mod;
            }
            i = j;
        }
    }
    if(!f) ans = 0;
    cout << ans << endl;
    return 0;
}
