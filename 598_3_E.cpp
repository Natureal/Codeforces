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
const int mod = 1000000007;

int n;
pii A[200010];
ll dp[200010];
int pre[200010];
int tot, team[200010];

bool Up(ll &a, ll b, ll plus){
    if(b == -1) return false;
    if(a == -1){
        a = b + plus;
        return true;
    }
    else if(b + plus < a){
        a = b + plus;
        return true;    
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> A[i].FI;
        A[i].SE = i;
    }
    sort(A + 1, A + n + 1);
    MEM(dp, -1);
    dp[0] = 0;
    REP(i, 3, n){
        REP(j, 0, 2){
            if(i - 3 - j >= 0){
                if(Up(dp[i], dp[i - 3 - j], A[i].FI - A[i - 3 - j + 1].FI)){
                    pre[i] = i - 3 - j;
                }
            }
        }
    }
    ll ans = dp[n];
    int ans_pre = pre[n];
    int pos = n;
    while(pos >= 1){
        ++tot;
        REP(i, ans_pre + 1, pos){
            team[A[i].SE] = tot;
        }
        pos = ans_pre;
        ans_pre = pre[ans_pre];
    }
    cout << ans << " " << tot << endl;
    REP(i, 1, n) cout << team[i] << " ";
    cout << endl;
    return 0;
}
