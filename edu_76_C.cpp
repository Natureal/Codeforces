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

int T, n;
int a[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        int ans = n + 1;
        map<int, int> mp;
        REP(i, 1, n){
            if(mp[a[i]]){
                ans = min(ans, i - mp[a[i]] + 1);
            }
            mp[a[i]] = i;
        }
        cout << ((ans > n) ? -1 : ans) << endl;
    }
    return 0;
}
