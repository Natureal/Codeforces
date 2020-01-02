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
int a[110], c[110];
unordered_map<string, int> mp;

int cal(int &a, int b, bool f){
    int ans = 0;
    int l = f ? 0 : 15, r = f ? 14 : 29;
    REP(i, l, r){
        ans += ((a ^ b) & (1 << i)) > 0;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> a[i];
    int ans = -1;
    REP(i, 0, (1 << 15) - 1){
        REP(j, 1, n){
            c[j] = cal(a[j], i, 1);
        }
        string ts;
        int tmin = 30;
        REP(j, 1, n) tmin = min(tmin, c[j]);
        REP(j, 1, n){
            ts += to_string(c[j] - tmin);
        }
        mp[ts] = i;
    }
    REP(i, 0, (1 << 15) - 1){
        REP(j, 1, n){
            c[j] = cal(a[j], i << 15, 0);
        }
        string ts;
        int tmax = 0;
        REP(j, 1, n) tmax = max(tmax, c[j]);
        REP(j, 1, n){
            ts += to_string(tmax - c[j]);
        }
        if(mp.find(ts) != mp.end()){
            ans = (i << 15) + mp[ts];
        }
    }
    cout << ans << endl;
    return 0;
}
