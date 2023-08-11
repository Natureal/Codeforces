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

int t, A, B, C, ans;

void Dfs(int p, int n, int a, int b, int c){
    if(p == 8){
        if(a <= A && b <= B && c <= C){
            ans = max(ans, n);
        }
        return;
    }
    Dfs(p + 1, n, a, b, c);
    Dfs(p + 1, n + 1, a + ((p & 1) > 0), b + ((p & 2) > 0), c + ((p & 4) > 0));
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    REP(q, 1, t){
        cin >> A >> B >> C;
        ans = 0;
        Dfs(1, 0, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
