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

int T, n, m;
pair<int, pii> r[110];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> n >> m;
        REP(i, 1, n){
            cin >> r[i].FI >> r[i].SE.FI >> r[i].SE.SE;
        }
        sort(r + 1, r + n + 1);
        int tn = 1;
        REP(i, 2, n){
            if(r[i].FI == r[tn].FI){
                r[tn].SE.FI = max(r[tn].SE.FI, r[i].SE.FI);
                r[tn].SE.SE = min(r[tn].SE.SE, r[i].SE.SE);
            }
            else{
                r[++tn] = r[i];
            }
        }
        n = tn;
        int time = 0, L = m, R = m;
        bool f = true;
        REP(i, 1, n){
            L -= r[i].FI - time;
            R += r[i].FI - time;
            time = r[i].FI;
            L = max(L, r[i].SE.FI);
            R = min(R, r[i].SE.SE);
            if(L > R){
                f = false;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
