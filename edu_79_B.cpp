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

int t, n, s;
int a[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> s;
        ll sum = 0;
        REP(i, 1, n){
            cin >> a[i];
            sum += a[i];
        }
        if(sum <= s){
            cout << 0 << endl;
            continue;
        }
        sum = 0;
        int tmax = 0, ans = 0, pos = 0, ans_pos = 0;
        REP(i, 1, n){
            sum += a[i];
            if(a[i] > tmax){
                tmax = a[i];
                pos = i;
            }
            if(sum - tmax <= s){
                ans = max(ans, i - 1);
                ans_pos = pos;
            }
        }
        cout << ans_pos << endl;
    }
    return 0;
}
