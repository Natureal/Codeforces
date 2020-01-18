// Segment Tree
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
const int maxn = 1000010;

int n, m, q;
int A[300010], B[300010];

struct SMT{
    int t[maxn << 2], add[maxn << 2];
    void build(int p, int l, int r){
        if(l == r){
            t[p] = add[p] = 0;
            return;
        }
        int mid = getmid(l, r);
        build(p << 1, l, mid);
        build(p << 1|1, mid + 1, r);
    }
    void push_down(int p){
        if(add[p]){
            t[p << 1] += add[p]; add[p << 1] += add[p];
            t[p << 1|1] += add[p]; add[p << 1|1] += add[p];
            add[p] = 0;
        }
    }
    void update(int a, int b, int c, int p, int l, int r){
        if(a <= l && r <= b){
            t[p] += c;
            add[p] += c;
            return;
        }
        int mid = getmid(l, r);
        if(add[p]) push_down(p);
        if(a <= mid) update(a, b, c, p << 1, l, mid);
        if(b > mid)  update(a, b, c, p << 1|1, mid + 1, r);
        t[p] = min(t[p << 1], t[p << 1|1]);
    }
    pii query_right_neg(int p, int l, int r){
        if(l == r) return MP(t[p], l);
        int mid = getmid(l, r);
        if(add[p]) push_down(p);
        if(t[p << 1|1] < 0) return query_right_neg(p << 1|1, mid + 1, r);
        else return query_right_neg(p << 1, l, mid);
    }
}smt;

int main(){
    ios_base::sync_with_stdio(false);
    int bound = 1e6;
    smt.build(1, 1, bound);
	cin >> n >> m;
    REP(i, 1, n){
        cin >> A[i];
        smt.update(1, A[i], -1, 1, 1, bound);
    }
    REP(i, 1, m){
        cin >> B[i];
        smt.update(1, B[i], 1, 1, 1, bound);
    }
    cin >> q;
    REP(i, 1, q){
        int f, a, b;
        cin >> f >> a >> b;
        if(f == 1){
            smt.update(1, A[a], 1, 1, 1, bound);
            A[a] = b;
            smt.update(1, A[a], -1, 1, 1, bound);
        }
        else{
            smt.update(1, B[a], -1, 1, 1, bound);
            B[a] = b;
            smt.update(1, B[a], 1, 1, 1, bound);
        }
        pii res = smt.query_right_neg(1, 1, bound);
        if(res.FI >= 0) cout << -1 << endl;
        else cout << res.SE << endl;
    }
    return 0;
}
