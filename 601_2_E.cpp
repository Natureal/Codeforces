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

int n, a[100010];

ll Cal(int k){
        ll ans = 0, pre = 0;
        VI V;
        REP(i, 1, n){
            if(a[i]){
                pre += a[i];
                V.PB(i);
            }
            if(pre == k){
                int center = k / 2;
                for(auto v: V){
                    ans += abs(v - V[center]);
                }
                pre = 0;
                V.clear();
            }
        }
        return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int sum = 0;
    REP(i, 1, n) cin >> a[i], sum += a[i];
    if(sum == 1){
        cout << -1 << endl;
    }
    else{
        int k = sum;
        ll ans = (1LL << 62) - 1;
        for(int i = 2; i <= k; ++i){
            if(sum % i == 0){
                ans = min(ans, Cal(i));
                while(sum % i == 0) sum /= i;
            }
        }
        if(sum > 1) ans = min(ans, Cal(sum));
        //printf("k: %d\n", k);
        cout << ans << endl;
    }
    return 0;
}
