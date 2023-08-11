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

int n, m, k;
int g[51][20010];
int sum[51][200010];

// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = 20010;

template<class T>
struct BIT{
    T t[maxn << 2], ad[maxn << 2];
    void push_down(int p){
        if(ad[p]){
            t[p << 1] += ad[p];
            ad[p << 1] += ad[p];
            t[p << 1|1] += ad[p];
            ad[p << 1|1] += ad[p];
            ad[p] = 0;
        }
    }
    void add(int a, int b, int c, int p, int l, int r){
        if(a <= l && r <= b){
            t[p] += c;
            ad[p] += c;
            return;
        }
        int mid = getmid(l, r);
        push_down(p);
        if(a <= mid) add(a, b, c, p << 1, l, mid);
        if(b > mid)  add(a, b, c, p << 1|1, mid + 1, r);
        t[p] = max(t[p << 1], t[p << 1|1]);
    }
};

BIT<int> bit[51];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
    REP(i, 1, n){
        REP(j, 1, m){
            cin >> g[i][j];
            sum[i][j] = sum[i][j - 1] + g[i][j];
        }
    }
    REP(j, 1, m - k + 1){
        int val = sum[1][j + k - 1] - sum[1][j - 1] + sum[2][j + k - 1] - sum[2][j - 1];
        bit[1].add(j, j, val, 1, 1, m);
    }
    REP(i, 2, n){
        REP(j, 1, k){
            int prej = max(1, j - k + 1);
            bit[i - 1].add(prej, j, -g[i][j], 1, 1, m);
        }
        int val = sum[i][k] + sum[i + 1][k];
        bit[i].add(1, 1, val + bit[i - 1].t[1], 1, 1, m);
        REP(j, 2, m - k + 1){
            int rj = j - 1;
            int prerj = max(1, rj - k + 1);
            bit[i - 1].add(prerj, rj, g[i][rj], 1, 1, m);
            int nj = j + k - 1;
            int prenj = max(1, nj - k + 1);
            bit[i - 1].add(prenj, nj, -g[i][nj], 1, 1, m);
            val = sum[i][j + k - 1] - sum[i][j - 1] + sum[i + 1][j + k - 1] - sum[i + 1][j - 1];
            bit[i].add(j, j, val + bit[i - 1].t[1], 1, 1, m);
        }
    }
    cout << bit[n].t[1] << endl;
    return 0;
}
