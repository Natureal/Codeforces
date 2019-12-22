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

int n, m;
int a[2010], b[2010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n) cin >> a[i];
    REP(i, 1, n) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = (1 << 30) - 1;
    REP(i, 1, n){
        // a[1] -> b[i]
        int x = ((b[i] - a[1]) % mod + m) % m;
        bool OK = true;
        REP(j, 2, n){
            int id = i + j - 1;
            if(id > n) id -= n;
            int y = ((b[id] - a[j]) % mod + m) % m;
            if(y != x){
                OK = false;
                break;
            }
        }
        if(OK) ans = min(ans, x);
    }
    cout << ans << endl;
    return 0;
}
