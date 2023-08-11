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

int q, n, r, x[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> q;
    REP(t, 1, q){
        cin >> n >> r;
        REP(i, 1, n) cin >> x[i];
        sort(x + 1, x + n + 1);
        int m = unique(x + 1, x + n + 1) - x - 1;
        ll sum = 0;
        int ans = 0;
        DEC(i, m, 1){
            if(x[i] - sum <= 0) break;
            ans++;
            sum += r;
        }
        cout << ans << endl;
    }
    return 0;
}
