#pragma GCC optimize("O3")
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
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;

int n;
int A[200010];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    if(n % 2){
        int tot = 0;
        REP(i, 1, n){
            if(i & 1) A[i] = tot + 1, A[i + n] = tot + 2;
            else A[i] = tot + 2, A[i + n] = tot + 1;
            tot += 2;
        }
        cout << "YES" << '\n';
        REP(i, 1, 2 * n) cout << A[i] << " ";
        cout << '\n';
    }
    else cout << "NO" << '\n';
    return 0;
}
