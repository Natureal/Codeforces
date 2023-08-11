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

int t;

int main(){
	int n;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int ans = 0;
		scanf("%d", &n);
		for(int tmp = 1; tmp < 10; ++tmp){
			ll st = tmp;
			while(st <= n){
				ans++;
				st = st * 10 + tmp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
