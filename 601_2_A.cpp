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

int t, n;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        int a, b;
        cin >> a >> b;
        int dif = abs(a - b);
        int v = dif % 5;
        int ans = dif / 5;
        if(v == 1 || v == 2) ans++;
        if(v == 3 || v == 4) ans += 2;
        cout << ans << endl;
    }
    return 0;
}
