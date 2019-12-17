#include <bits/stdc++.h>
using namespace std;
 
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;

int a, b, c, d, e, f;

int main(){
	cin >> a >> b >> c >> d >> e >> f;
	ll ans = 0;
	for(int i = 0; i <= min(a, d); ++i){
		ans = max(ans, 1LL * i * e + 1LL * min(b, min(c, d - i)) * f);
	}
	cout << ans << endl;
	return 0;
}
