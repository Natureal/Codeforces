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

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        int c[2][2];
        MEM(c, 0);
        cin >> n;
        REP(i, 1, n){
            int a;
            cin >> a;
            c[0][a & 1]++;
        }
        cin >> m;
        REP(i, 1, m){
            int a;
            cin >> a;
            c[1][a & 1]++;
        }
        cout << 1LL * c[0][0] * c[1][0] + 1LL * c[0][1] * c[1][1] << endl;
    }
    return 0;
}
