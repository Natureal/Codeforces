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

int t, h, n, p[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> h >> n;
        int ans = 0;
        REP(i, 1, n){
            cin >> p[i];
        }
        p[n + 1] = 0;
        int pos = p[1];
        REP(i, 2, n){
            if(pos > p[i]) pos = p[i] + 1;
            if(pos - p[i + 1] > 2){
                ans++;
            }
            else pos = p[i + 1], i++;
        }
        cout << ans << endl;
    }
    return 0;
}
