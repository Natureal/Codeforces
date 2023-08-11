#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;

int t;
ll n, m;
ll a[100010];
int num[62]; 

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        MEM(num, 0);
        cin >> n >> m;
        REP(i, 1, m){
            cin >> a[i];
            ll tmp = a[i], k = 0;
            while(tmp % 2 == 0){
                tmp /= 2;
                k++;
            }
            num[k]++;
        }
        int ans = 0;
        bool f = true;
        REP(i, 0, 60){
            if(n & (1LL << i)){
                if(num[i] > 0){
                    num[i]--;
                    n ^= (1LL << i);
                }
                else{
                    int pos = -1;
                    REP(j, i + 1, 60) if(num[j]){
                        pos = j;
                        break;
                    }
                    if(pos == -1){
                         f = false;
                         break;
                    }
                    for(int j = pos; j > i; --j){
                        num[j]--;
                        num[j - 1] += 2;
                        ans++;
                    }
                    num[i]--;
                    n ^= (1LL << i);
                }
            }
            if(num[i] > 0){
                num[i + 1] += num[i] / 2;
            }
        }
        if(!f) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
