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

int n, l[300010], r[300010];
char s[300010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> s + 1;
    REP(i, 1, n){
        l[i] = i;
        if(i > 1 && s[i] == s[i - 1]) l[i] = l[i - 1];
    }
    DEC(i, n, 1){
        r[i] = i;
        if(i < n && s[i] == s[i + 1]) r[i] = r[i + 1];
    }
    ll ans = 0, f = 0;
    REP(i, 1, n){
        if(i > 1 && s[i] != s[i - 1]){
            f++;
            ans += (i - l[i - 1]);
        }
        if(i < n && s[i] != s[i + 1]){
            f++;
            ans += (r[i + 1] - i);
        }
    }
    cout << 1LL * n * (n - 1) / 2 - (ans - f / 2) << endl;
    return 0;
}
