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

int n, k;
ll a[200010];

bool check(ll v){
    int p = n / 2 + 1;
    ll sum = 0;
    REP(i, p, n){
        sum += max(0LL, v - a[i]);
    }
    return sum <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
    REP(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 1, r = 2 * 1000 * 1000 * 1000 + 1;
    while(l < r){
        ll mid = getmid(l, r);
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    if(check(l) == false) l--;
    cout << l << endl;
    return 0;
}
