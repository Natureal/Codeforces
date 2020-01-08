#include <iostream>
#include <queue>
#include <vector>
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

int n, A[200010], par[200010], dis[200010];
VI g[200010];

int main(){
    ios_base::sync_with_stdio(false);
	queue<int> Q;
	cin >> n;
	REP(i, 1, n) cin >> A[i], par[i] = (A[i] & 1);
	REP(i, 1, n){
		bool f = false;
		if(i - A[i] >= 1 && par[i - A[i]] != par[i]) f = true;
		if(i + A[i] <= n && par[i + A[i]] != par[i]) f = true;
		if(!f){
			if(i - A[i] >= 1) g[i - A[i]].PB(i);
			if(i + A[i] <= n) g[i + A[i]].PB(i);
			dis[i] = 1e9;
		}
		else{
			dis[i] = 1;
			Q.push(i);
		}
	}
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(auto v: g[x]){
			if(dis[v] > dis[x] + 1){
				dis[v] = dis[x] + 1;
				Q.push(v);
			}
		}
	}
	REP(i, 1, n) cout << ((dis[i] == 1e9) ? -1 : dis[i]) << " ";
	cout << endl;
    return 0;
}
