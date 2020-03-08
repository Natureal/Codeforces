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

int n, m;
int A[5010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    ll sum = 0, cur = 0;
    A[1] = 1;
    A[2] = 2;
    REP(i, 3, n){
        if(i % 2) cur++;
        if(m >= cur){
            A[i] = i;
            m -= cur;
        }
        else{
            A[i] = i - 1 + i - 2 * m;
            m = 0;
            REP(j, i + 1, n){
                A[j] = A[j - 1] + A[i] + 1;
            }
            break;
        }
    }
    if(m > 0){
        cout << -1 << endl;
        return 0;
    }
    REP(i, 1, n) cout << A[i] << " ";
    cout << endl;
    return 0;
}
