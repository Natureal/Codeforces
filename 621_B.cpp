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

int t, n, x;
int a[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> x;
        REP(i, 1, n) cin >> a[i];
        int tmax = 0;
        bool f = false;
        REP(i, 1, n){
            if(a[i] <= x) tmax = max(tmax, a[i]);
            else f = true;
        }
        if(tmax == 0){
            cout << 2 << endl;
            continue;
        }
        int k = x / tmax;
        if(x % tmax) k++;
        if(f) k = min(k, 2);
        cout << k << endl;
    }
    return 0;
}
