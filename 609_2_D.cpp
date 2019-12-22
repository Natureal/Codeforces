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
const int mod = 1000000007;

int n, a[300010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> a[i];
    ll ans = 0;
    int pre = 0, odd = 0;
    REP(i, 1, n){
        int j = i;
        while(j + 1 <= n && a[j + 1] == a[i]) j++;
        int L = j - i + 1;
        if(L & 1){
            if(pre == 0){
                ans += 1LL * a[i] * L / 2;
                if(a[i] & 1){
                    pre = 1;
                    odd = 1; 
                }   
            }
            else{
                int top = 0;
                if(odd) top = 2 * pre - 1;
                else top = 2 * pre;
                while(top > a[i]){
                    top -= 2;
                    pre--;
                }
                while(a[i] - 2 >= top){
                    ans += 1LL * L;
                    a[i] -= 2;
                }
                ans += 1LL * a[i] * (L / 2) + pre;
                if(odd){
                    if(top == a[i]) pre--;
                }
                else{
                    if(top < a[i]) pre++;
                }
                odd ^= 1; 
            }
        }
        else{
            ans += 1LL * a[i] * L / 2;
        }
       // printf("i %d , pre %d, odd %d, ans %lld\n", i, pre, odd, ans);
        i = j;
    }
    cout << ans << endl;
    return 0;
}
