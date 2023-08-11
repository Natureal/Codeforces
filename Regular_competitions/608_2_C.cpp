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

int n, sx, sy;
int X[200010], Y[200010], D[200010];

int Cal(int a1, int b1, int a2, int b2){
	return abs(a1 - a2) + abs(b1 - b2);
}

int Proc(int tx, int ty){
	int num = 0;
	for(int i = 0; i < n; ++i){
		if(Cal(tx, ty, X[i], Y[i]) + 1 == D[i]){
			num++;
		}
	}
	return num;
}

int main(){
	cin >> n >> sx >> sy;
	for(int i = 0; i < n; ++i){
		cin >> X[i] >> Y[i];
		D[i] = Cal(X[i], Y[i], sx, sy);
	}
	int ans = 0, tx, ty;
	int res = Proc(sx - 1, sy);
	if(res > ans){
		ans = res;
		tx = sx - 1;
		ty = sy;
	}
	if((res = Proc(sx, sy - 1)) > ans){
		tx = sx;
		ty = sy - 1;
		ans = res;
	}
	if((res = Proc(sx  + 1, sy)) > ans){
		tx = sx + 1;
		ty = sy;
		ans = res;
	}
	if((res = Proc(sx, sy + 1)) > ans){
		tx = sx;
		ty = sy + 1;
		ans = res;
	}
	cout << ans << endl;
	cout << tx << " " << ty << endl;
	return 0;
}
