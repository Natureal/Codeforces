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

int t, n, k;
ll A[110], pw[1100];
int vis[1100];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    REP(q, 1, t){
        cin >> n >> k;
        int tot = 0;
        pw[0] = 1;
        VL avai;
        avai.PB(1);
        REP(i, 1, 1000){
            pw[i] = 1LL * pw[i - 1] * k;
            if(pw[i] > 1LL * 10000 * 10000 * 10000 * 10000){
                tot = i;
                break;
            }
            avai.PB(pw[i]);
        }
        MEM(vis, 0);
        reverse(avai.begin(), avai.end());
        REP(i, 1, n){
            cin >> A[i];
        }
        bool f = true;
        REP(i, 1, n){
            REP(j, 0, SZ(avai) - 1) if(vis[j] == 0){
                if(A[i] >= avai[j]){
                    A[i] -= avai[j];
                    vis[j] = 1;
                }
            }
            if(A[i] > 0){
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
