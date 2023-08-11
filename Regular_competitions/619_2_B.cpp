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

int t, n;
int a[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        int tmin = 1e9 + 1, tmax = -2;
        REP(i, 1, n){
            if(a[i] == -1){
                if(i > 1 && a[i - 1] != -1){
                    tmin = min(tmin, a[i - 1]);
                    tmax = max(tmax, a[i - 1]);
                }
                if(i < n && a[i + 1] != -1){
                    tmin = min(tmin, a[i + 1]);
                    tmax = max(tmax, a[i + 1]);
                }
            }
        }
        if(tmax == -2){
            tmin = tmax = 0;
        }
        REP(i, 1, n) if(a[i] == -1) a[i] = tmin + (tmax - tmin) / 2;
        int v = tmin + (tmax - tmin) / 2;
        tmax = 0;
        REP(i, 1, n){
            if(i > 1) tmax = max(tmax, abs(a[i - 1] - a[i]));
            if(i < n) tmax = max(tmax, abs(a[i + 1] - a[i]));
        }
        cout << tmax << " " << v << endl;
    }
    return 0;
}
