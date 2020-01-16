#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): *(s.find_by_order(2), counting from 0)
// order_of_key(k) returns the number of items strictly smaller than item k.
template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, 
        tree_order_statistics_node_update>;

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

int n, m;
int a[300010];
pii ans[300010];
bool vis[300010];
int pre[300010];

// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = 300010;

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

BIT<int> bt1, bt2;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n) ans[i] = MP(i, i);
    REP(i, 1, m){
        cin >> a[i];
    }
    REP(i, 1, m){
        if(vis[a[i]] == false){
            vis[a[i]] = true;
            int res = bt1.get(n) - bt1.get(a[i]);
            ans[a[i]].SE = max(ans[a[i]].SE, a[i] + res);
            ans[a[i]].FI = 1;
            bt1.add(a[i], 1);
            //printf("bt %d\n", i);
            bt2.add(i, 1);
        }
        else{
            int res = bt2.get(i) - bt2.get(pre[a[i]]);
            ans[a[i]].SE = max(ans[a[i]].SE, res + 1);
            ans[a[i]].FI = 1;
            bt2.add(pre[a[i]], -1);
            bt2.add(i, 1);
        }
        pre[a[i]] = i;
    }
    REP(i, 1, n){
        if(vis[i] == false){
            int res = bt1.get(n) - bt1.get(i);
            ans[i].SE = max(ans[i].SE, i + res);
        }
        else{
            int res = bt2.get(m) - bt2.get(pre[i]);
            //printf("%d , pre %d res %d\n", i, pre[i], res);
            ans[i].SE = max(ans[i].SE, res + 1);
        }
    }
    REP(i, 1, n){
        cout << ans[i].FI << " " << ans[i].SE << endl;
    }
    return 0;
}
