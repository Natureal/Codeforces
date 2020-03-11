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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int l, int r){
    // produces a random integer, uniformly distributed on [l, r]
    return uniform_int_distribution<int>(l, r)(rng);
}

char A[110], B[110], S[210];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 100;
    cout << T << endl;
    REP(q, 1, T){
        int n = 1 + rand_int(6, 10), m = 1 + rand_int(1, 2);
        REP(i, 1, n){
            A[i] = 'a' + rand_int(0, 2);
            B[i] = 'a' + rand_int(0, 2);
        }
        REP(i, 1, m){
            S[i] = 'a' + rand_int(0, 2);
        }
        A[n + 1] = B[n + 1] = S[m + 1] = '\0';
        cout << n << " " << m << endl;
        cout << A + 1 << endl;
        cout << B + 1 << endl;
        cout << S + 1 << endl;
    }
    return 0;
}
