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

bool v[200010];

int main(){
    ios_base::sync_with_stdio(false);
	int n;
    cin >> n;
    v[0] = true;
    int ans = 0;
    REP(i, 1, n){
        int a;
        cin >> a;
        if(v[a - 1]){
            v[a] = true;
            ans = max(ans, a);
        }
    }
    cout << (ans ? n - ans : -1) << endl;
    return 0;
}
