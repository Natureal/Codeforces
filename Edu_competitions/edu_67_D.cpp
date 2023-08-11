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

int t, n;
int a[300010], b[300010];
int tree[300010 << 2];
VI G[300010];

void build(int p, int l, int r){
    if(l == r){
        tree[p] = a[l];
        return;
    }
    int mid = getmid(l, r);
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    tree[p] = min(tree[p << 1], tree[p << 1|1]);
}

void update(int a, int c, int p, int l, int r){
    if(l == r){
        tree[p] = c;
        return;
    }
    int mid = getmid(l, r);
    if(a <= mid) update(a, c, p << 1, l, mid);
    else update(a, c, p << 1|1, mid + 1, r);
    tree[p] = min(tree[p << 1], tree[p << 1|1]);
}

int query(int a, int b, int p, int l, int r){
    if(a <= l && r <= b){
        return tree[p];
    }
    int mid = getmid(l, r);
    int res = 1e9;
    if(a <= mid) res = min(res, query(a, b, p << 1, l, mid));
    if(b > mid)  res = min(res, query(a, b, p << 1|1, mid + 1, r));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        REP(i, 1, n) G[i].clear();
        REP(i, 1, n) cin >> a[i], G[a[i]].PB(i);
        REP(i, 1, n) reverse(G[i].begin(), G[i].end());
        REP(i, 1, n) cin >> b[i];
        build(1, 1, n);
        bool f = true;
        REP(i, 1, n){
            if(SZ(G[b[i]]) == 0){
                f = false;
                break;
            }
            int p = G[b[i]][SZ(G[b[i]]) - 1];
            G[b[i]].pop_back();
            int tmin = query(1, p, 1, 1, n);
            if(tmin < b[i]){
                f = false;
                break;
            }
            update(p, 1e9, 1, 1, n);
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
