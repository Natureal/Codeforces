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

int n;
bool f[100010];
int tmin[100010], tmax[100010], tmax_b[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        int m;
        cin >> m;
        int pre_tmin = 1e9;
        tmax[i] = -1;
        REP(j, 1, m){
            int v;
            cin >> v;
            if(v > pre_tmin) f[i] = true;
            else pre_tmin = v;
            tmax[i] = max(tmax[i], v);
        }
        tmin[i] = pre_tmin;
    }
    int num_f = 0;
    REP(i, 1, n) num_f += f[i];
    int tot = 0;
    REP(i, 1, n) if(!f[i]){
        tmax_b[++tot] = tmax[i];
    }
    sort(tmax_b + 1, tmax_b + tot + 1);
    ll ans = 0;
    REP(i, 1, n){
        if(f[i]) ans += n;
        else{
            ans += num_f;
            int pos = upper_bound(tmax_b + 1, tmax_b + tot + 1, tmin[i]) - tmax_b;
            if(pos <= tot){
                ans += tot - pos + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
