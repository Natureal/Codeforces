// Hash
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): *(s.find_by_order(2), counting from 0)
// order_of_key(k) returns the number of items strictly smaller than item k.
template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, 
        tree_order_statistics_node_update>;

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
const int maxn = 500010;

struct Hash{
    // hash is 1-based index, but the input and output are 0-based index
    int base[2][maxn], hs[2][maxn], len;
    int B[2] = {239, 229}, mod[2] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9};
    void init(char *s, int L = -1){
        len = (L == -1) ? strlen(s) : L;
        base[0][0] = base[1][0] = 1;
        hs[0][0] = hs[1][0] = 0;
        REP(i, 1, len) REP(j, 0, 1){
            base[j][i] = 1LL * base[j][i - 1] * B[j] % mod[j];
            hs[j][i] = (1LL * hs[j][i - 1] * B[j] % mod[j] + s[i - 1]) % mod[j];
        }
    }
    pii get(int l, int r){ // 0-based index
        int res[2];
        REP(i, 0, 1)
            res[i] = ((hs[i][r + 1] - 1LL * hs[i][l] * base[i][r - l + 1] % mod[i]) % mod[i]
                        + mod[i]) % mod[i];
        return MP(res[0], res[1]);
    }
};

Hash HS;

char s[500010], t[500010], ans[500010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> s >> t;
    int num0 = 0, num1 = 0;
    int lens = strlen(s), lent = strlen(t);
    REP(i, 0, lens - 1){
        num0 += (s[i] == '0');
        num1 += (s[i] == '1');
    }
    HS.init(t, lent);
    int suf = 0;
    REP(i, 1, lent - 1){
        if(HS.get(0, lent - i - 1) == HS.get(i, lent - 1)){
            suf = lent - i;
            break;
        }
    }
    int tot = 0;
    REP(i, 0, lent - 1){
        if(t[i] == '0'){
            if(num0 > 0) ans[tot++] = '0', num0--;
            else if(num1 > 0) ans[tot++] = '1', num1--;
            else break;
        }
        else{
            if(num1 > 0) ans[tot++] = '1', num1--;
            else if(num0 > 0) ans[tot++] = '0', num0--;
            else break;
        }
    }
    while(num0 || num1){
        REP(i, suf, lent - 1){
            if(t[i] == '0'){
                if(num0 > 0) ans[tot++] = '0', num0--;
                else if(num1 > 0) ans[tot++] = '1', num1--;
                else break;
            }
            else{
                if(num1 > 0) ans[tot++] = '1', num1--;
                else if(num0 > 0) ans[tot++] = '0', num0--;
                else break;
            }
        }
    }
    ans[tot] = '\0';
    cout << ans << endl;
    return 0;
}
