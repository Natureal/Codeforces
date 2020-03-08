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

int n, m, p;
int A[1000010], B[1000010];

inline int Read(){
      int x = 0,f = 1;char ch = getchar();
      while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
      while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
      return x * f;
}

int main(){
    n = Read();
    m = Read();
    p = Read();
    REP(i, 1, n) A[i] = Read();
    REP(i, 1, m) B[i] = Read();
    int a, b;
    REP(i, 1, n) if(A[i] % p){
        a = i;
        break;
    }
    REP(i, 1, m) if(B[i] % p){
        b = i;
        break;
    }
    cout << a + b - 2 << endl;
    return 0;
}
