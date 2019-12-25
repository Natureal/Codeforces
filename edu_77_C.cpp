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

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(false);
	int t;
    cin >> t;
    REP(q, 1, t){
        int r, b, k;
        cin >> r >> b >> k;
        if(r > b) swap(r, b);
        int m = (b - gcd(r, b) - 1) / r + 1;
        if(m >= k) cout << "REBEL" << endl;
        else cout << "OBEY" << endl;
    }
    return 0;
}
