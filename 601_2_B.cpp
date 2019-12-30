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
typedef vector<int> VI;
const int mod = 1000000007;

int t, n, m;
int a[1010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> m;
        REP(i, 1, n) cin >> a[i];
        if(m < n || n == 2){
            cout << -1 << endl;
        }
        else{
            ll sum = 0;
            REP(i, 1, n) sum += 2LL * a[i];
            cout << sum << endl;
            REP(i, 1, n - 1){
                cout << i << " " << i + 1 << endl;
            }
            cout << n << " " << 1 << endl;
        }
    }
    return 0;
}
