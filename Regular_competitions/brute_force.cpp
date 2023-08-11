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

char A[110], B[110], S[210];
int T, n, m;

bool check(int a, int b, int c){
    REP(i, a, b){
        if(S[i - a + 1] != A[i]) return false;
    }
    int rem = m - (b - a + 1);
    REP(i, c, c + rem - 1){
        if(S[b - a + 1 + i - c + 1] != B[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    REP(q, 1, T){
        cin >> n >> m;
        cin >> A + 1 >> B + 1 >> S + 1;
        int ans = 0;
        REP(i, 1, n){
            REP(j, i, n){
                if(j - i + 1 > m - 1) break;
                int rem = m - (j - i + 1);
                REP(k, 1, n - rem + 1){
                    if(k > j || k + rem - 1 < i) continue;
                    if(check(i, j, k)){
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
