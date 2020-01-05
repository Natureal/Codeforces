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

int n, m;
string s[21], t[21];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, 0, n - 1){
        cin >> s[i];
    }
    REP(i, 0, m - 1){
        cin >> t[i];
    }
    int q;
    cin >> q;
    REP(i, 1, q){
        int y;
        cin >> y;
        cout << s[(y - 1) % n] + t[(y - 1) % m] << endl;
    }
    return 0;
}
