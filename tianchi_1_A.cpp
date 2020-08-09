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

int n, k, b, m;
ll A[6000010];
int s0;
ll a;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> A[1] >> n >> k >> b >> m >> a;
    int p = 1;
    ll ans = 0;
    REP(i, 2, n){
        A[i] = (A[i - 1] * k + b) % m + 1 + A[i - 1];
        if(p == i - 1 && A[i] * A[i] <= a){
            p++;
        }
        while(p > 0 && A[i] * A[p] > a){
            p--;
        }
        ans += p;
    }
    cout << ans << endl;
    return 0;
}
