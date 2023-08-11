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
vector<string> G;
char s[12];

void Dfs(int p, int tot){
    //:cout << p << " , " << tot << endl;
    if(p > n){
        cout << s + 1 << '\n';
        return;
    }
    REP(i, 0, tot){
        s[p] = 'a' + i;
        Dfs(p + 1, tot);
    }
    s[p] = 'a' + tot + 1;
    Dfs(p + 1, tot + 1);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    s[n + 1] = '\0';
    Dfs(1, -1);
    return 0;
}
