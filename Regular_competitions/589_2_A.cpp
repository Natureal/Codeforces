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

int l, r;

int solve(){
    for(int i = l; i <= r; ++i){
        map<int, int> g;
        int tmp = i;
        bool f = true;
        while(tmp){
            if(g[tmp % 10]){
                f = false;
                break;
            }
            g[tmp % 10] = 1;
            tmp /= 10;
        }
        if(f) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> l >> r;
    cout << solve() << endl;
    return 0;
}
