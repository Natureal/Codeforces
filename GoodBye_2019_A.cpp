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

int n, k1, k2;

int main(){
    ios_base::sync_with_stdio(false);
	int t;
    cin >> t;
    REP(q, 1, t){
        int tmax1 = 0, tmax2 = 0;
        cin >> n >> k1 >> k2;
        REP(i, 1, k1){
            int a;
            cin >> a;
            tmax1 = max(tmax1, a);
        }
        REP(i, 1, k2){
            int a;
            cin >> a;
            tmax2 = max(tmax2, a);
        }
        if(tmax1 > tmax2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
