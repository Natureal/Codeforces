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
VI G[1010];
int d[1010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n - 1){
        int a, b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
        d[a]++;
        d[b]++;
    }
    queue<int> Q;
    REP(i, 1, n) if(d[i] == 1){
        Q.push(i);
    }
    int ans;
    while(!Q.empty()){
        int a = Q.front(); Q.pop();
        if(Q.empty()){
            ans = a;
            break;
        }
        int b = Q.front(); Q.pop();
        cout << "? " << a << " " << b << endl;
        cout.flush();
        int c;
        cin >> c;
        if(c == a){
            ans = a;
            break;
        }
        if(c == b){
            ans = b;
            break;
        }
        d[a]--;
        for(auto v: G[a]){
            d[v]--;
            if(d[v] == 1) Q.push(v);
        }
        d[b]--;
        for(auto v: G[b]){
            d[v]--;
            if(d[v] == 1) Q.push(v);
        }
    }
    cout << "! " << ans << endl;
    cout.flush();
    return 0;
}
