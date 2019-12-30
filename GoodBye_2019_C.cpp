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

int n;

int main(){
    ios_base::sync_with_stdio(false);
	int t;
    cin >> t;
    REP(q, 1, t){
        cin >> n;
        ll sum = 0, xor_sum = 0;
        REP(i, 1, n){
            int a;
            cin >> a;
            sum += a;
            xor_sum ^= a;
        }
        xor_sum *= 2;
        if(sum == xor_sum){
            cout << 0 << endl << endl;
        }
        else{
            //cout << sum << " , " << xor_sum << endl;
            ll ans = 0;
            REP(i, 0, 62){
                ll v = 1LL << i;
                if((sum & v) != (xor_sum & v)){
                    //cout << "here: " << v << endl;
                    ans |= v;
                    sum += v;
                    xor_sum ^= (v * 2LL);
                }
            }
            cout << 1 << endl << ans << endl;
        }

    }
    return 0;
}
