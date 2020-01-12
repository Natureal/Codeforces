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

int t, n;
pii S[200010];
pii rmax[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        map<int, int> mp;
        cin >> n;
        REP(i, 1, n){
            cin >> S[i].FI >> S[i].SE;
        }
        sort(S + 1, S + n + 1);
        int cnt = 0;
        rmax[0] = MP(-1e9 - 100, -1e9 - 100);
        cnt = 0;
        REP(i, 1, n){
            rmax[i] = rmax[i - 1];
            if(S[i].SE > rmax[i].FI){
                rmax[i].SE = rmax[i].FI;
                rmax[i].FI = S[i].SE;
            }
            else if(S[i].SE > rmax[i].SE){
                rmax[i].SE = S[i].SE;
            }
            if(rmax[i - 1].FI < S[i].FI){
                cnt++;
            }
            if(rmax[i - 1].FI >= S[i].FI && rmax[i - 1].SE < S[i].FI){
                mp[rmax[i - 1].FI]++;
            }
        }
        int ans = cnt - 1;
        REP(i, 1, n){
            if(S[i].SE > rmax[i - 1].FI){
                int v = mp[S[i].SE];
                ans = max(ans, (rmax[i - 1].FI >= S[i].FI) + cnt + v - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
