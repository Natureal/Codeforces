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

int n;
int A[510];
int dp[510][510];
int st[510];

int Cal(int l, int r){
    int tot = 0;
    REP(i, l, r){
        int a = A[i];
            while(tot > 0){
                if(st[tot] != a) break;
                tot--;
                a++;
            }
        st[++tot] = a;
    }
    return tot;
}

int Solve(int l, int r){
    if(dp[l][r]) return dp[l][r];
    if(l == r) return 1;
    int res = Cal(l, r);
    REP(i, l + 1, r){
        res = min(res, Solve(l, i - 1) + Solve(i, r));
    }
    return dp[l][r] = res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    REP(i, 1, n){
        cin >> A[i];
    }
    int ans = Solve(1, n);
    cout << ans << '\n';
    return 0;
}
