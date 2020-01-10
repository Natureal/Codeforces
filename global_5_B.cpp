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

int n, a[100010], b[100010], p[100010], pos[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> a[i], p[a[i]] = i;
    REP(i, 1, n){
        cin >> b[i];
    }
    int ans = 0;
    DEC(i, n, 1){
        pos[i] = p[b[i]];
        if(i < n) pos[i] = min(pos[i], pos[i + 1]);
    }
    REP(i, 1, n){
        if(p[b[i]] > pos[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
