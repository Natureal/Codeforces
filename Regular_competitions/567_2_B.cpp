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

int l;
char s[100010];
int ans[100010], ans_tot, tmp[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> l >> s + 1;
    int num = 1e9, st = 10, p = -1;
    REP(i, 2, l) if(s[i] != '0'){
        int bit = max(i - 1, l - i + 1);
        int val = (i - 1 > l - i + 1) ? s[1] - '0' : s[i] - '0';
        if(bit < num){
            p = i;
            num = bit;
            st = val;
        }
    }
    REP(i, 2, l) if(s[i] != '0'){
        int bit = max(i - 1, l - i + 1);
        if(bit == num){
            int tot = 1, p1 = i - 1, p2 = l, carry = 0;
            while(p1 > 0 || p2 >= i || carry){
                int v1 = (p1 > 0) ? s[p1] - '0' : 0;
                int v2 = (p2 >= i) ? s[p2] - '0' : 0;
                if(p1 > 0) p1--;
                if(p2 >= i) p2--;
                tmp[tot] = v1 + v2 + carry;
                carry = tmp[tot] / 10;
                tmp[tot] %= 10;
                ++tot;
            }
            if(ans_tot == 0){
                memcpy(ans, tmp, sizeof(tmp));
                ans_tot = tot;
                MEM(tmp, 0);
            }
            else{
                bool f = tot < ans_tot;
                if(tot == ans_tot){
                    DEC(i, tot - 1, 1){
                        //printf("%d %d\n", tmp[i], ans[i]);
                        if(tmp[i] < ans[i]){
                            f = true;
                            break;
                        }
                        if(tmp[i] > ans[i]) break;
                    }
                }
                if(f){
                    memcpy(ans, tmp, sizeof(tmp));
                    ans_tot = tot;
                    MEM(tmp, 0);
                }
            }
        }
    }
    DEC(i, ans_tot - 1, 1) cout << ans[i];
    cout << endl;
    return 0;
}
