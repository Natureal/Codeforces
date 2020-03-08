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
VI G[200010];
VI B;
ll dp[200010][2];
int L[200010], R[200010];

void Update(ll &a, ll b){
    if(a == -1) a = b;
    else a = min(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> q;
    REP(i, 1, k){
        int a, b;
        cin >> a >> b;
        G[a].PB(b);
    }
    G[1].PB(1);
    REP(i, 1, n){
        sort(G[i].begin(), G[i].end());
        if(SZ(G[i])){
            L[i] = G[i][0];
            R[i] = G[i][SZ(G[i]) - 1];
        }
        else{
            L[i] = R[i] = -1;
        }
    }
    REP(i, 1, q){
        int b;
        cin >> b;
        B.PB(b);
    }
    sort(B.begin(), B.end());
    MEM(dp, -1);
    if(R[1] != -1){
        dp[1][0] = -1;
        dp[1][1] = R[1] - 1;
    }
    int pre = 1;
    ll ans = dp[1][1];
    REP(i, 2, n) if(R[i] != -1){
        int pos1 = -1, pos2 = lower_bound(B.begin(), B.end(), L[pre]) - B.begin();
        if(pos2 >= SZ(B)){
            pos2--;
            pos1 = pos2;
        }
        else if(B[pos2] == L[pre]){
            pos1 = pos2;
        }
        else if(pos2 > 0){
            pos1 = pos2 - 1;
        }
        else{
            pos1 = pos2;
        }
        ll cost;
        if(dp[pre][0] != -1){
        // 0 1 0
        cost = R[i] - L[i] + min(abs(L[pre] - B[pos2]) + abs(B[pos2] - R[i]), 
                                    abs(L[pre] - B[pos1]) + abs(B[pos1] - R[i]));
        Update(dp[i][0], dp[pre][0] + i - pre + cost);
        // 0 0 1
        cost = R[i] - L[i] + min(abs(L[pre] - B[pos2]) + abs(B[pos2] - L[i]),
                                 abs(L[pre] - B[pos1]) + abs(B[pos1] - L[i]));
        Update(dp[i][1], dp[pre][0] + i - pre + cost);
        }
        pos1 = -1, pos2 = lower_bound(B.begin(), B.end(), R[pre]) - B.begin();
        if(pos2 >= SZ(B)){
            pos2--;
            pos1 = pos2;
        }
        else if(B[pos2] == R[pre]){
            pos1 = pos2;
        }
        else if(pos2 > 0){
            pos1 = pos2 - 1;
        }
        else{
            pos1 = pos2;
        }
        if(dp[pre][1] != -1){
        // 1 1 0
        cost = R[i] - L[i] + min(abs(R[pre] - B[pos2]) + abs(B[pos2] - R[i]),
                                 abs(R[pre] - B[pos1]) + abs(B[pos1] - R[i]));
        Update(dp[i][0], dp[pre][1] + i - pre + cost);
        // 1 0 1
        cost = R[i] - L[i] + min(abs(R[pre] - B[pos2]) + abs(B[pos2] - L[i]),
                                 abs(R[pre] - B[pos1]) + abs(B[pos1] - L[i]));
        Update(dp[i][1], dp[pre][1] + i - pre + cost);
        }
        ans = (1LL << 60);
        if(dp[i][0] != -1) ans = min(ans, dp[i][0]);
        if(dp[i][1] != -1) ans = min(ans, dp[i][1]);
        //cout << "i: " << i << " , " << dp[i][0] << " and " << dp[i][1] << endl;
        //printf("B: %d %d\n", B[pos1], B[pos2]);
        pre = i;
    }
    cout << ans << endl;
    return 0;
}
