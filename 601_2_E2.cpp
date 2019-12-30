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
typedef pair<ll,ll> pll;
typedef vector<int> VI;
const int mod = 1000000007;

int n;
int a[1000010];

ll Cal(ll k){
    ll ans = 0, pre = 0;
    vector<pll> V;
    REP(i, 1, n){
        if(a[i] % k){
            pre += a[i] % k;
            V.PB(MP(i, a[i] % k));
        }
        if(pre >= k){
            pre %= k;
            vector<pll> nxt_V;
            if(pre){
                V[SZ(V) - 1].SE -= pre;
                nxt_V.PB(MP(i, pre));
            }
            ll suf_sum = 0, sum = 0;
            REP(j, 0, SZ(V) - 1){
                suf_sum += V[j].SE;
                sum += 1LL * (V[j].FI - V[0].FI) * V[j].SE;
            }
            ll pre_sum = 0, tmp_ans = sum;
            REP(j, 0, SZ(V) - 2){
                pre_sum += V[j].SE;
                suf_sum -= V[j].SE;
                sum = sum - 1LL * suf_sum * (V[j + 1].FI - V[j].FI) + 
                            1LL * pre_sum * (V[j + 1].FI - V[j].FI);
                tmp_ans = min(tmp_ans, sum);
            }
            ans += tmp_ans;
            V = nxt_V;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    ll sum = 0;
    REP(i, 1, n) cin >> a[i], sum += a[i];
    if(sum == 1){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> V;
    ll t_sum = sum;
    for(ll i = 2; i * i <= sum; ++i){
        if(t_sum % i == 0){
            V.PB(i);
            while(t_sum % i == 0) t_sum /= i;
        }
    }
    if(t_sum > 1) V.PB(t_sum);
    ll ans = (1LL << 62) - 1;
    for(auto v: V){
        ans = min(ans, Cal(v));
    }
    cout << ans << endl;
    return 0;
}
