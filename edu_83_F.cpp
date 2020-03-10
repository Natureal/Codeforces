// Games, SG Pattern Finding
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

int t, n, x, y, z;
ll A[300010];
int sg[1010][3];
bool sghash[1010];
int K[3], circle;

int get(int a, int b){
    MEM(sghash, 0);
    REP(i, 0, 2) if(b == 0 || b != i){
        sghash[sg[max(0, a - K[i])][i]] = true;
    }
    REP(j, 0, 1000){
        if(!sghash[j]) return j;
    }
    return -1;
}

bool check(int len){
    REP(i, 1, 2){
        REP(j, 0, len - 1){
            REP(k, 0, 2){
                if(sg[200 - j][k] != sg[200 - i * len - j][k]){
                    return false;
                }
            }
        }
    }
    return true;
}

int cal(ll a, int b){
    if(a <= 100) return sg[a][b];
    return sg[(a - 100) % circle + 100][b];
}

int main(){
    //ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    REP(q, 1, t){
        cin >> n >> K[0] >> K[1] >> K[2];
        REP(i, 1, n) cin >> A[i];
        MEM(sg, 0);
        REP(i, 1, 210){
            REP(j, 0, 2){
                sg[i][j] = get(i, j);
                //if(i < 50) printf("sg[%d][%d]: %d,  ", i, j, sg[i][j]);
            }
            //if(i < 50) printf("\n");
        }
        circle = 0;
        DEC(i, 15, 1){
            if(check(i)){
                circle = i;
                //cout << "circle: " << circle << '\n';
                break;
            }
        }
        int sum = 0;
        REP(i, 1, n){
            sum ^= cal(A[i], 0);
        }
        int ans = 3 * n;
        REP(i, 1, n){
            REP(j, 0, 2){
                if(sum ^ cal(A[i], 0) ^ cal(max(0LL, A[i] - K[j]), j)) ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
