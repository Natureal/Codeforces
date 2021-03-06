// KMP
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

char s[500010], t[500010], ans[500010];
int fail[500010];

void Get_fail(char *s, int L = -1){
    fail[0] = -1;
    int j = -1, len = (L == -1) ? strlen(s) : L;
    REP(i, 1, len - 1){
        while(j >= 0 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        fail[i] = j;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> s >> t;
    int num0 = 0, num1 = 0;
    int lens = strlen(s), lent = strlen(t);
    REP(i, 0, lens - 1){
        num0 += (s[i] == '0');
        num1 += (s[i] == '1');
    }
    Get_fail(t, lent);
    int suf = fail[lent - 1] + 1;
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
