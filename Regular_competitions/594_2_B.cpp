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

int n; ll a[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    ll sum = 0;
    ll tmin = 1e9;
    REP(i, 1, n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    ll pre = 0;
    REP(i, 1, n / 2){
        pre += a[i];
    }
    cout << 1LL * pre * pre + 1LL * (sum - pre) * (sum - pre) << endl;
    return 0;
}
