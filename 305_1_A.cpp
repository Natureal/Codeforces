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

int m, h[2], a[2], x[2], y[2], cur[2];
int vis[2][1000010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> m;
    cin >> h[0] >> a[0];
    cin >> x[0] >> y[0];
    cin >> h[1] >> a[1];
    cin >> x[1] >> y[1];
    MEM(vis, -1);
    REP(i, 0, 1){
        int cir = 0;
        while(1){
            if(vis[i][h[i]] == -1){
                vis[i][h[i]] = cir;
            }
            else{
                cur[i] = cir - vis[i][h[i]];
                if(vis[i][a[i]] < vis[i][h[i]]) cur[i] = 0;
                break;
            }
            h[i] = (1LL * x[i] * h[i] % m + y[i]) % m;
            cir++;
        }
    }
    ll ans = -1;
    if(vis[0][a[0]] == -1 || vis[1][a[1]] == -1) ans = -1;
    else if(vis[0][a[0]] == vis[1][a[1]]) ans = vis[0][a[0]];
    else if(cur[1] == 0){
        if(vis[1][a[1]] > vis[0][a[0]] && (vis[1][a[1]] - vis[0][a[0]]) % cur[0] == 0)
            ans = vis[1][a[1]];
    }
    else{
        REP(i, 0, 2000000) if(vis[0][a[0]] + 1LL * i * cur[0] >= vis[1][a[1]]){
            if((vis[0][a[0]] + 1LL * i * cur[0] - vis[1][a[1]]) % cur[1] == 0){
                ans = vis[0][a[0]] + 1LL * i * cur[0];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
