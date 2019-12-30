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
int a[200010], A[200010], B[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        REP(i, 1, n) A[i] = a[i] - i;
        REP(i, 1, n) B[i] = a[i] + i;
        int ans_l = -1, ans_r = -1;
        int minA = A[1] + 1, maxB = B[1] - 1;
        int pA = 1, pB = 1;
        REP(i, 2, n){
            if(A[i] >= minA){
                ans_l = pA;
                ans_r = i;
                break;
            }
            if(B[i] <= maxB){
                ans_l = pB;
                ans_r = i;
                break;
            }
            if(a[i] - i + 1 < minA){
                minA = a[i] - i + 1;
                pA = i;
            }
            if(a[i] + i - 1 > maxB){
                maxB = a[i] + i - 1;
                pB = i;
            }
        }
        if(ans_l == -1) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << ans_l << " " << ans_r << endl;
        }
    }
    return 0;
}
