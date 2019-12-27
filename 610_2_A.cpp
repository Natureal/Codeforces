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

int t;

int Get(int a1, int b1, int a2, int b2){
    return max(0, min(b1, b2) - max(a1, a2));
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        cout << b - a - Get(a, b, c - r, c + r) << endl;
    }
    return 0;
}
