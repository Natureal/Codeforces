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

int main(){
    ios_base::sync_with_stdio(false);
	int t;
    cin >> t;
    REP(q, 1, t){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int dif = b - a;
        int ta = a - dif, tb = b - 2 * dif;
        if(ta == tb && ta % 3 == 0 && ta >= 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
