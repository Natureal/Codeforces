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

int n;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        int c, sum;
        cin >> c >> sum;
        if(c >= sum){
            cout << sum << endl;
        }
        else{
            int rem = sum % c;
            int num = sum / c;
            cout << 1LL * (c - rem) * num * num + 1LL * rem * (num + 1) * (num + 1) << endl;
        }
    }
    return 0;
}
