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
typedef vector<int> VI;
const int mod = 1000000007;

int t, l, r;
int bit[100], bit2[100];
ll dp[100][2][2][2][2];

ll Dfs(int p, bool below1, bool below2, bool up1, bool up2){
    if(p == -1){
        return 1;
    }
    if(dp[p][below1][below2][up1][up2]){
        return dp[p][below1][below2][up1][up2];
    }
    ll ans = 0;
    if((up1 || !bit2[p]) && (up2 || !bit2[p])) 
        ans += Dfs(p - 1, below1 | bit[p], below2 | bit[p], up1, up2);
    if((up1 || !bit2[p]) && (below2 || bit[p])) 
        ans += Dfs(p - 1, below1 | bit[p], below2, up1, up2 | !bit2[p]);
    if((below1 || bit[p]) && (up2 || !bit2[p]))
        ans += Dfs(p - 1, below1, below2 | bit[p], up1 | !bit2[p], up2);
    return dp[p][below1][below2][up1][up2] = ans;
}

ll S(int v1, int v2){
    int i = 0, j = 0;
    while(v1){
        bit[i++] = v1 & 1;
        v1 /= 2;
    }
    while(v2){
        bit2[j++] = v2 & 1;
        v2 /= 2;
    }
    return Dfs(i - 1, 0, 0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        MEM(dp, 0);
        MEM(bit2, 0);
        MEM(bit, 0);
        cin >> l >> r;
        cout << S(r, l) << endl;
    }
    return 0;
}
