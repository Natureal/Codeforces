#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define DEC(i, a, b) for(int i = b; i >= a; --i)
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

int t;

int main(){
	cin >> t;
    REP(o, 1, t){
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int ans = 0;
        while(a < b){
            ans++;
            a += ans;
        }
        while((a - b) % 2){
            ans++;
            a += ans;
        }
        cout << ans << endl;
    }
    return 0;
}
