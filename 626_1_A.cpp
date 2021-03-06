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
char s[1000010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    cin >> s + 1;
    int cur = 0, pre = -1;
    int ans = 0;
    REP(i, 1, n){
        if(s[i] == '('){
            cur++;
        }
        else{
            cur--;
        }
        if(cur < 0){
            if(pre == -1) pre = i;
        }
        if(cur == 0 && pre != -1){
            ans += i - pre + 1;
            pre = -1;
        }
    }
    cout << (cur == 0 ? ans : -1) << endl;
    return 0;
}
