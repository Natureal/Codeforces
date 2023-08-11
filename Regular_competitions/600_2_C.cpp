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

int n, m;
int a[200010];
ll sum[200010], p_sum[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll cur = 0;
    REP(i, 1, n){
        cur += p_sum[i % m] + a[i];
        p_sum[i % m] += a[i];
        cout << cur << " ";
    }
    cout << endl;
    return 0;
}
