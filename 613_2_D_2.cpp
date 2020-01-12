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
 
int n, A[100010];
 
int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    VI tmp;
    REP(i, 1, n) cin >> A[i], tmp.PB(A[i]);
    int ans = 0;
    vector<vector<int> > G[2];
    G[0].PB(tmp);
    int id = 0;
    bool f = false;
    DEC(j, 29, 0){
        bool no_need = false;
        for(auto v: G[id]){
            VI v0, v1;
            for(auto item: v){
                if(item & (1 << j)) v1.PB(item);
                else v0.PB(item);
            }
            if(SZ(v0) == 0 || SZ(v1) == 0){
                if(!no_need) G[id ^ 1].clear();
                no_need = true;
            }
            if(no_need && SZ(v0) && SZ(v1)) continue;
            if(SZ(v0)) G[id ^ 1].PB(v0);
            if(SZ(v1)) G[id ^ 1].PB(v1);
        }
        if(f) break;
        if(!no_need) ans |= (1 << j);
        G[id].clear();
        id ^= 1;
    }
    cout << ans << endl;
    return 0;
}
