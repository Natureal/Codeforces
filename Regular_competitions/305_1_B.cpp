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

int n;
pii A[200010], R[200010];
int ans[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> A[i].FI;
        A[i].SE = i;
    }
    sort(A + 1, A + n + 1);
    DEC(i, n, 1){
        int pos = A[i].SE;
        R[pos] = MP(pos, pos);
        if(pos > 1 && R[pos - 1].FI) R[pos].FI = R[pos - 1].FI;
        if(pos < n && R[pos + 1].SE) R[pos].SE = R[pos + 1].SE;
        R[R[pos].FI].SE = R[pos].SE;
        R[R[pos].SE].FI = R[pos].FI;
        int L = R[pos].SE - R[pos].FI + 1;
        ans[L] = max(ans[L], A[i].FI);
    }
    DEC(i, n - 1, 1) ans[i] = max(ans[i], ans[i + 1]);
    REP(i, 1, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
