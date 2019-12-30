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

int N, M, V, P;
int A[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> N >> M >> V >> P;
    REP(i, 1, N){
        cin >> A[i];
    }
    sort(A + 1, A + N + 1, greater<int>());
    ll ans = P;
    ll pre = A[P], pre_num = 1;
    REP(i, P + 1, N){
        if(i + V - 1 > N){
            int m = i + V - 1 - N;
            if(m + 1 <= P){
                if(A[i] + M >= A[m + 1]) ans++;
            }
            else{
                int left = m + 1 - P;
                ll left_sum = 1LL * pre_num * (A[i] + M) - pre;
                if(left_sum >= 1LL * left * M){
                    ans++;
                }
            }
        }
        else{
            if(A[i] + M >= A[P]){
                ans++;
            }
        }
        pre += A[i];
        pre_num++;
    }
    cout << ans << endl;
    return 0;
}
