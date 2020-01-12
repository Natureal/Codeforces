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

int n, m, ans[200010];
pii t[200010];
int pos[200010];

// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = 200010;

template<class T>
struct BIT{
    T c[maxn];
    BIT(){ clear(); }
    inline void clear(){ memset(c, 0, sizeof(c)); }
    inline T lowbit(T x){ return x & (-x); }
    inline void add(int x, T d){
        while(x <= maxn){
            c[x] += d;
            x += lowbit(x);
        }
    }
    inline T get(int x){
        T res = 0;
        while(x){
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    }
};

BIT<ll> bt, bt_num;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n){
        cin >> t[i].FI;
        t[i].SE = i;
    }
    sort(t + 1, t + n + 1);
    REP(i, 1, n){
        bt.add(i, t[i].FI);
        bt_num.add(i, 1);
        pos[t[i].SE] = i;
    }
    DEC(i, n, 1){
        int p = pos[i];
        bt.add(p, -t[p].FI);
        bt_num.add(p, -1);
        int l = 1, r = n;
        while(l < r){
            int mid = getmid(l, r);
            if(bt.get(mid) <= m - t[p].FI) l = mid + 1;
            else r = mid;
        }
        if(bt.get(l) > m - t[p].FI) l--;
        ans[i] = i - 1 - bt_num.get(l);
        //printf("i %d: %d %d, l: %d\n", i, t[p].FI, t[p].SE, l);
    }
    REP(i, 1, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
