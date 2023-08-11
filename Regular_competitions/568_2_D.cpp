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
pll b[200010];
int pre[200010], suf[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> b[i].FI, b[i].SE = i;
    sort(b + 1, b + n + 1);
    REP(i, 1, n){
        if(i <= 2) pre[i] = 1;
        else if(b[i].FI - b[i - 1].FI == b[i - 1].FI - b[i - 2].FI){
            pre[i] = pre[i - 1];
        }
        else{
            pre[i] = i;
        }
    }
    DEC(i, n, 1){
        if(i >= n - 1) suf[i] = n;
        else if(b[i + 1].FI - b[i].FI == b[i + 2].FI - b[i + 1].FI){
            suf[i] = suf[i + 1];
        }
        else{
            suf[i] = i;
        }
    }
    int ans = -1;
    if(suf[2] == n) ans = b[1].SE;
    if(pre[n - 1] == 1) ans = b[n].SE;
    REP(i, 2, n - 1){
        if(pre[i - 1] == 1 && suf[i + 1] == n){
            ll dif = b[i + 1].FI - b[i - 1].FI;
            bool f = true;
            if(i - 2 >= 1 && b[i - 1].FI - b[i - 2].FI != dif) f = false;
            if(i + 2 <= n && b[i + 2].FI - b[i + 1].FI != dif) f = false;
            if(f){
                ans = b[i].SE;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
