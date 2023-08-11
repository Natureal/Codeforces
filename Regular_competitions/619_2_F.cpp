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

int n, m, k, q;
int g[1010][1010], dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dp[41][1010][1010], vis[41], inq[1010][1010];
VPI V[41];

int main(){
    ios_base::sync_with_stdio(false);
	scanf("%d%d%d", &n, &m, &k);
    REP(i, 1, n){
        REP(j, 1, m){
            scanf("%d", &g[i][j]);
            V[g[i][j]].PB(MP(i, j));
        }
    }
    MEM(dp, -1);
    REP(i, 1, k){
        MEM(vis, 0);
        MEM(inq, 0);
        vis[i] = 1;
        queue<pii > Q;
        for(auto p: V[i]){
            dp[i][p.FI][p.SE] = 1;
            Q.push(p);
            inq[p.FI][p.SE] = 1;
        }
        while(!Q.empty()){
            pii cur = Q.front(); Q.pop();
            inq[cur.FI][cur.SE] = 0;
            REP(o, 0, 3){
                int ti = cur.FI + dir[o][0], tj = cur.SE + dir[o][1];
                if(ti < 1 || ti > n || tj < 1 || tj > m) continue;
                if(dp[i][ti][tj] == -1 || dp[i][ti][tj] > dp[i][cur.FI][cur.SE] + 1){
                    dp[i][ti][tj] = dp[i][cur.FI][cur.SE] + 1;
                   if(inq[ti][tj] == 0){
                       Q.push(MP(ti, tj));
                       inq[ti][tj] = 1;
                    }     
                }
            }
            int co = g[cur.FI][cur.SE];
            if(vis[co] == 0){
                vis[co] = 1;
                for(auto p: V[co]){
                    if(dp[i][p.FI][p.SE] == -1 || dp[i][p.FI][p.SE] > dp[i][cur.FI][cur.SE] + 1){
                        dp[i][p.FI][p.SE] = dp[i][cur.FI][cur.SE] + 1;
                        if(inq[p.FI][p.SE] == 0){
                            Q.push(p);
                            inq[p.FI][p.SE] = 1;
                        }
                    }
                }
            }
        }
    }
    scanf("%d", &q);
    REP(i, 1, q){
        int a1, b1, a2, b2;
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        int ans = abs(a1 - a2) + abs(b1 - b2);
        REP(c, 1, k){
            ans = min(ans, dp[c][a1][b1] + dp[c][a2][b2] - 1);
        } 
        printf("%d\n", ans);
    }
    return 0;
}
