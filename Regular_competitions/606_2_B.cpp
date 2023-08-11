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

int t, n;
int A[200010];
int num[200010];
map<int, int> mp;
map<int, int>::iterator it;

int main(){
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> n;
		mp.clear();
		memset(num, 0, sizeof(num));
		for(int i = 1; i <= n; ++i){
			scanf("%d", &A[i]);
			while(A[i] % 2 == 0){
				A[i] /= 2;
				num[i]++;
			}
			mp[A[i]] = max(mp[A[i]], num[i]);
		}
		int ans = 0;
		for(it = mp.begin(); it != mp.end(); ++it){
			ans += (*it).second;
		}
		cout << ans << endl;
	}
	return 0;
}
