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
	int a, b;
    cin >> a >> b;
    cout << 1LL * a * b / gcd(a, b) << endl;
    return 0;
}
