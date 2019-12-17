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

int n, m , k;
int A[5010], B[5010], C[5010], rem[5010];
int late[5010];
int dp[5010][5010];
vector<int> V[5010];
priority_queue<int> Q;

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i){
		cin >> A[i] >> B[i] >> C[i];
		late[i] = i;
	}
	A[n + 1] = 0;
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		late[v] = max(late[v], u);
	}
	for(int i = 1; i <= n; ++i){
		V[late[i]].PB(C[i]);
	}
	for(int i = n - 1; i >= 1; --i){
		A[i] = max(A[i], A[i + 1] - B[i]);
	}
	bool f = true;
	for(int i = 1; i <= n; ++i){
		if(k < A[i]){
			f = false;
			break;
		}
		k += B[i];
		rem[i] = k - A[i + 1];
		k = A[i + 1];
	}
	if(!f){
		cout << "-1" << endl;
		return 0;
	}
	int ans = 0, cur = 0;
	for(int i = n; i >= 1; --i){
		for(int j = 0; j < V[i].size(); ++j) Q.push(V[i][j]);
		cur = rem[i];
		while(!Q.empty() && cur > 0){
			ans += Q.top();
			Q.pop();
			cur--;
		}
	}
	cout << ans << endl;
	return 0;
}
