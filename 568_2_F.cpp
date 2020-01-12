// Submask DP
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
const int mod = 1000000007;

int n, m, sta[512], peo[512];
pll cost[512];
pii C[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        int f;
        cin >> f;
        int s = 0;
        REP(j, 1, f){
            int a;
            cin >> a;
            s |= (1 << (a - 1));
        }
        sta[s]++;
    }
    REP(i, 1, m){
        int c, r;
        cin >> c >> r;
        C[i] = MP(c, i);
        int s = 0;
        REP(j, 1, r){
            int a;
            cin >> a;
            s |= (1 << (a - 1));
        }
        if(cost[s].FI == 0) cost[s] = MP(c, i);
        else if(c < cost[s].FI){
            cost[s] = MP(c, i);
        }
    }
    sort(C + 1, C + m + 1);
    for(int s = 0; s < (1 << 9); ++s){
        for(int d = s; d; d = (d - 1) & s){
            peo[s] += sta[d];
        }
    }
    pii ans = MP(0, 0);
    ll ans_peo = 0, ans_c = 0;
    for(int s = 0; s < (1 << 9); ++s) if(cost[s].FI){
        for(int s2 = 0; s2 < (1 << 9); ++s2) if(cost[s2].FI){
            if(peo[s | s2] > ans_peo){
                ans_peo = peo[s | s2];
                ans_c = cost[s].FI + cost[s2].FI;
                ans = MP(cost[s].SE, cost[s2].SE);
            }
            else if(peo[s | s2] == ans_peo && cost[s].FI + cost[s2].FI < ans_c){
                ans_c = cost[s].FI + cost[s2].FI;
                ans = MP(cost[s].SE, cost[s2].SE);
            }
        }
    }
    if(ans_peo == 0) ans = MP(C[1].SE, C[2].SE);
    else if(ans.FI == ans.SE) ans.SE = C[2].SE;
    cout << ans.FI << " " << ans.SE << endl;
    return 0;
}
