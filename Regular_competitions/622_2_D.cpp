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

int n, m, k;
pii Q[200010];
int dp[200010][1 << 8], ended[200010], judge[1 << 8];
VI G[200010];

int cal(int x){
    int c = 0;
    REP(i, 0, 7) if(x & (1 << i)) c++;
    return c % 2;
}

int cal_dis(int a, int last){
    if(last == -1) return 0;
    else return a - last;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    REP(i, 0, (1 << 8) - 1) judge[i] = cal(i);
    cin >> n >> m >> k;
    REP(i, 1, n){
        int a, b;
        cin >> a >> b;
        Q[i * 2 - 1].FI = a;
        Q[i * 2 - 1].SE = i;
        Q[i * 2].FI = b;
        Q[i * 2].SE = -i;
    }
    sort(Q + 1, Q + 2 * n + 1);
    REP(i, 1, 2 * n) G[i].reserve(k);
    int id = 1, last = -1, ans = 0;
    REP(i, 1, 2 * n){
        int j = i;
        while(j + 1 <= 2 * n && Q[j + 1].FI == Q[i].FI) j++;
        int c = 0, pre_c = 0;
        REP(k, i, j) if(Q[k].SE > 0) G[id].PB(Q[k].SE), c++;
        int pren = SZ(G[id - 1]);
        REP(k, 0, pren - 1) if(!ended[G[id - 1][k]]) pre_c++;
        REP(sta, 0, (1 << pren) - 1){
            int nxt_sta = 0;
            DEC(k, pren - 1, 0) if(!ended[G[id - 1][k]]){
                nxt_sta = (nxt_sta << 1) + ((sta & (1 << k)) > 0);
            }
            REP(plus, 0, (1 << c) - 1){
                int tsta = nxt_sta + (plus << pre_c);
                dp[id][tsta] = max(dp[id][tsta], dp[id - 1][sta] + judge[tsta] + 
                        judge[nxt_sta] * cal_dis(Q[i].FI, last));
                //printf("plus: %d, nxt_sta: %d, dp[%d][%d]: %d -> dp[%d][%d]: %d\n", plus, nxt_sta, id - 1, sta, dp[id - 1][sta], id, tsta, dp[id][tsta]);
            }   
        }
        REP(k, i, j) if(Q[k].SE < 0) ended[-Q[k].SE] = 1;
        for(auto v: G[id]) if(!ended[v]) G[id + 1].PB(v);
        id++;
        last = Q[i].FI + 1;
        i = j;
    }
    REP(i, 1, id){
        REP(sta, 0, (1 << SZ(G[i])) - 1){
            ans = max(ans, dp[i][sta]);
        }
    }
    cout << ans << '\n';
    return 0;
}
