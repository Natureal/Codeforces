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
const int maxn = (1 << 24);

int n;
int A[400010];

// The range of bit is [1, maxn]. Do not store any value at index 0.
template<class T>
struct BIT{
    T c[maxn + 10];
    BIT(){ clear(); }
    inline void clear(){ memset(c, 0, sizeof(c)); }
    inline int lowbit(int x){ return x & (-x); }
    inline void add(int x, T d){
        while(x <= maxn){
            c[x] ^= d;
            x += lowbit(x);
        }
    }
    inline T get(int x){
        T res = 0;
        while(x){
            res ^= c[x];
            x -= lowbit(x);
        }
        return res;
    }
};

BIT<bool> bit[25];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int ans = 0;
    REP(i, 1, n){
        cin >> A[i];
        int v = 0;
        REP(j, 0, 24){
            if(A[i] & (1 << j)){
                v |= (1 << j);
            }
            int top = (1 << (j + 1)) - 1;
            int bot = (1 << j);
            int L = max(0, bot - v), R = min(10000000, top - v);
            int res;
            if(L <= R){
                res = bit[j].get(R + 1);
                if(L > 0) res ^= bit[j].get(L);
                if(res) ans ^= (1 << j);
            }
            top = (1 << (j + 2)) - 1;
            bot = (1 << (j + 1)) + (1 << j);
            L = max(0, bot - v), R = min(10000000, top - v);
            if(L <= R){
                res = bit[j].get(R + 1);
                if(L > 0) res ^= bit[j].get(L);
                if(res) ans ^= (1 << j);
            }
        }
        v = 0;
        REP(j, 0, 24){
            if(A[i] & (1 << j)){
                v |= (1 << j);
            }
            //printf("i %d, j %d, v: %d\n", i, j, v);
            bit[j].add(v + 1, 1);
        }
    }
    cout << ans << endl;
    return 0;
}
