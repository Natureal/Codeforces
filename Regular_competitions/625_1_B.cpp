#pragma GCC optimize("O3")
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
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;
const int INF = (1 << 30) - 1;

int n, m;
VI G[200010], GP[200010];
int dis[200010], inq[200010];
int P[200010];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    REP(i, 1, m){
        int a, b;
        cin >> a >> b;
        G[b].PB(a);
        GP[a].PB(b);
    }
    int K;
    cin >> K;
    REP(i, 1, K){
        cin >> P[i];
    }
    fill(dis, dis + n + 1, INF);
    dis[P[K]] = 0;
    queue<int> Q;
    Q.push(P[K]);
    inq[P[K]] = 1;
    while(!Q.empty()){
        int p = Q.front(); Q.pop();
        inq[p] = 0;
        for(auto v: G[p]){
            if(dis[v] > dis[p] + 1){
                dis[v] = dis[p] + 1;
                if(inq[v] == 0){
                    inq[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    REP(i, 1, K - 1){
        int num = 0;
        for(auto v: GP[P[i]]){
            if(dis[v] == dis[P[i]] - 1){
                num++;
            }
        }
        if(dis[P[i + 1]] == dis[P[i]] - 1){
            if(num > 1) ans2++;
        }
        else{
            ans1++;
            ans2++;
        }
    }
    cout << ans1 << " " << ans2 << '\n';
    return 0;
}
