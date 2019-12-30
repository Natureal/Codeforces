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

ll N, A, B;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> N >> A >> B;
    if(A > B) swap(A, B);
    if((B - A) % 2 == 0){
        cout << (B - A) / 2 << endl;
    }
    else{
        ll ans = A - 1 + ((B - A) + 1) / 2;
        ans = min(ans, N - B + ((B - A) + 1) / 2);
        cout << ans << endl;
    }
    return 0;
}
