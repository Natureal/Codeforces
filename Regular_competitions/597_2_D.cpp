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
typedef pair<ll, ll> pll;
typedef vector<int> VI;
const int mod = 1000000007;

int n;
pii P[2010];
ll c[2010], k[2010];
ll dist[2010];
int pre[2010];
bool vis[2010];

struct cmp{
    bool operator ()(pll a, pll b){
        return a.FI > b.FI;
    }
};

priority_queue<pll, vector<pll >, cmp> PQ;

ll cal(int a, int b){
    return 1LL * (abs(P[a].FI - P[b].FI) + abs(P[a].SE - P[b].SE)) * (k[a] + k[b]);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> P[i].FI >> P[i].SE;
    REP(i, 1, n) cin >> c[i];
    REP(i, 1, n) cin >> k[i];
    ll tmin = c[1], pos = 1;
    REP(i, 1, n){
        if(c[i] < tmin){
            tmin = c[i];
            pos = i;
        }
    }
    REP(i, 1, n) dist[i] = c[i];
    PQ.push(MP(dist[pos], pos));
    ll ans = 0;
    while(!PQ.empty()){
        pll x = PQ.top(); PQ.pop();
        if(dist[x.SE] < x.FI) continue;
        vis[x.SE] = 1;
        ans += x.FI;
        ll ttmin = (1LL << 62) - 1, nxt = 0;
        REP(i, 1, n) if(!vis[i]){
            if(dist[i] > cal(x.SE, i)){
                dist[i] = cal(x.SE, i);
                pre[i] = x.SE;
            }
            if(dist[i] < ttmin){
                ttmin = dist[i];
                nxt = i;
            }
        }
        if(nxt) PQ.push(MP(dist[nxt], nxt));
    }
    cout << ans << endl;
    int num = 0, edge = 0;
    REP(i, 1, n){
        if(!pre[i]) num++;
        else edge++;
    }
    cout << num << endl;
    REP(i, 1, n) if(!pre[i]) cout << i << " ";
    cout << endl;
    cout << edge << endl;
    REP(i, 1, n) if(pre[i]){
        cout << i << " " << pre[i] << endl;
    }
    return 0;
}
