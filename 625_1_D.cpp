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

int n;
char s[200010];
int q;
int B = 239, H[200010], BP[200010], num[200010];
int prefix[200010], suffix[200010];

int Q_pow(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

int cal(int a, int len){
    if(a == 1) return H[len];
    if(prefix[a - 1] % 2 == 0 || suffix[a] == 0 || (prefix[a - 1] + min(suffix[a], len)) % 2 == 1){
        return (H[a + len - 1] - 1LL * H[a - 1] * BP[num[a + len - 1] - num[a - 1]] % mod + mod) % mod;
    }
    else{
        int hpre = 1LL * (1LL * H[a - 1] - '1' + mod) % mod * Q_pow(B, mod - 2) % mod;
        int hsuf = (H[a + len - 1] - 1LL * hpre * BP[num[a + len - 1] - (num[a - 1] - 1)] % mod + mod) % mod;
        hsuf = (1LL * hsuf + 1LL * '1' * BP[num[a + len - 1] - (num[a - 1] - 1)] % mod) % mod;
        return hsuf;
    }
}

int main(){
   // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> s + 1;
    int base = 1, pre = 0;
    BP[0] = 1;
    REP(i, 1, n) BP[i] = 1LL * BP[i - 1] * B % mod;
    REP(i, 1, n){
        prefix[i] = (s[i] == '1') ? prefix[i - 1] + 1 : 0;
    }
    DEC(i, n, 1){
        suffix[i] = (s[i] == '1') ? suffix[i + 1] + 1 : 0;
    }
    REP(i, 1, n){
        if(s[i] == '1'){
            if(pre % 2 == 0){
                H[i] = (1LL * H[i - 1] * B % mod + '1') % mod;
                num[i] = num[i - 1] + 1;
            }
            else{
                H[i] = H[i - 2];
                num[i] = num[i - 1] - 1;
            }
            pre++;
        }
        else{
            H[i] = (1LL * H[i - 1] * B % mod + '0') % mod;
            pre = 0;
            num[i] = num[i - 1] + 1;
        }
    }
    cin >> q;
    REP(i, 1, q){
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        //cout << cal(l1, len) << " , " << cal(l2, len) << endl;
        if(cal(l1, len) == cal(l2, len)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
