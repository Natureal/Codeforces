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

int t, n;
int a[100010], b[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        REP(i, 1, n){
            cin >> b[i];
            b[i] -= a[i];
        }
        bool f = true;
        REP(i, 1, n) if(b[i] < 0){
            f = false;
            break;
        }
        int start = 0;
        REP(i, 1, n){
            if(b[i]){
                if(i == 1 || b[i] != b[i - 1]){
                    start++;
                }
            }
        }
        if(f && start <= 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
