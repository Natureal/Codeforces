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

int T;
ll x, y;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> x >> y;
        while(y % 3 == 0) y = y / 3 * 2;
        while(x < y){
            ll nx;
            if(x % 2 == 0) nx = x / 2 * 3;
            else nx = (x - 1) / 2 * 3;
            if(nx <= x) break;
            x = nx;
        }
        if(x >= y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
