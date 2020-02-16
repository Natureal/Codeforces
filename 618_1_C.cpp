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
const double eps = 1e-12;

int n;
double a[1000010], sum[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> a[i];
    int t = 15;
    while(t--){
        REP(i, 1, n) sum[i] = sum[i - 1] + a[i];
        REP(i, 1, n){
            int j = i;
            double pre = a[i];
            while(j + 1 <= n && (a[j + 1] == a[i] || (sum[j + 1] - sum[i - 1]) / (j - i + 2) <= pre)){
                pre = (sum[j + 1] - sum[i - 1]) / (j - i + 2);
                j++;
            }
            double val = (sum[j] - sum[i - 1]) / (j - i + 1);
            REP(k, i, j) a[k] = val;
            i = j;
        }
    }
    REP(i, 1, n){
        printf("%.12lf\n", a[i]);
    }
    return 0;
}
