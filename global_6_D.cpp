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

int n, m;
ll in[100010], out[100010];
int ans1[300010], ans2[300010];
ll ans3[300010];
int tot = 0;

int main(){
	cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        in[v] += d;
        out[u] += d;
    }
    for(int i = 1; i <= n; ++i){
        ll tmin = min(in[i], out[i]);
        in[i] -= tmin;
        out[i] -= tmin;
    }
    int k = 1;
    for(int i = 1; i <= n; ++i){
        while(out[i]){
            while(in[k] == 0 && k < n) ++k;
            ll tmin = min(out[i], in[k]);
            out[i] -= tmin;
            in[k] -= tmin;
            ans1[++tot] = i;
            ans2[tot] = k;
            ans3[tot] = tmin;
        }
    }
    cout << tot << endl;
    for(int i = 1; i <= tot; ++i){
        cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << endl;
    }
    return 0;
}
