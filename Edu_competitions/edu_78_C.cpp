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

int t, n;
int a[200010];

int main(){
	cin >> t;
    REP(o, 1, t){
        cin >> n;
        int num1 = 0;
        map<int, int> mp;
        REP(i, -2 * n, 2 * n) mp[i] = 3 * n;
        mp[0] = n;
        REP(i, 1, 2 * n){
            cin >> a[i];
            if(a[i] == 1) num1++;
            else num1--;
            if(i <= n){
                mp[num1] = min(mp[num1], n - i);
                if(i == n) num1 = 0;
            }
        }
        int ans = min(2 * n, mp[-num1]);
        REP(i, n + 1, 2 * n){
            if(a[i] == 1) num1--;
            else num1++;
            ans = min(ans, mp[-num1] + i - n);
        }
        cout << ans << endl;
    }
    return 0;
}
