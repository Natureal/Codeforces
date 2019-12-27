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

int m, n, T, a, b;
pii t[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> m;
    REP(q, 1, m){
        cin >> n >> T >> a >> b;
        REP(i, 1, n) cin >> t[i].SE;
        REP(i, 1, n) cin >> t[i].FI;
        t[n + 1] = MP(T + 1, 0);
        sort(t + 1, t + n + 2);
        ll n_0 = 0, n_1 = 0;
        REP(i, 1, n){
            if(t[i].SE == 0) n_0++;
            else n_1++;
        }
        ll sum = 0, pre = 0, ans = 0;
        REP(i, 1, n + 1){
            ll time = t[i].FI - 1 - sum;
            if(time >= 0){
                ll tmp_0 = max(0LL, min(n_0, time / a));
                ll tmp_1 = max(0LL, min(n_1, (time - tmp_0 * a) / b));
                //printf("%d, time: %lld, t: %d, 0: %lld, 1: %lld\n", i, time, t[i].FI, tmp_0, tmp_1);
                ans = max(ans, pre + tmp_0 + tmp_1);
            }
            sum += (t[i].SE == 0) ? a : b;
            if(t[i].SE == 0) n_0--;
            else n_1--;
            pre++;
        }
        cout << ans << endl;
    }
    return 0;
}
