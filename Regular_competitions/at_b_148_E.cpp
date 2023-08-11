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
const int mod = 1000000007;

ll N;

ll f(ll v, ll k){
    if(v < k) return 0;
    return v / k / 2 + f(v / k, k);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> N;
    if(N & 1LL){
        cout << 0 << endl;
        return 0;
    }
    cout << f(N, 5) << endl;
    return 0;
}
