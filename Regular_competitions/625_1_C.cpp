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
const ll INF = (1LL << 60);

const int maxn = 1000 * 1000;

int n, m, P;
pii A[200010];
int B[200010], CB[200010];
int C[1000010];

struct M{
    int x, y, z;
}mon[200010];

template<class T>
struct SMT{
    T t[maxn << 2], add[maxn << 2];
    void clear(){
        MEM(t, 0);
        MEM(add, 0);
    }
    void push_down(int p){
        if(add[p]){
            t[p << 1] += add[p];
            add[p << 1] += add[p];
            t[p << 1|1] += add[p];
            add[p << 1|1] += add[p];
            add[p] = 0;
        }
    }
    void build(int p, int l, int r){
        if(l == r){
            if(C[l] == 0) t[p] = -INF;
            else t[p] = C[l];
            return;
        }
        int mid = getmid(l, r);
        build(p << 1, l, mid);
        build(p << 1|1, mid + 1, r);
        t[p] = max(t[p << 1], t[p << 1|1]);
    }
    void update(int a, int b, T c, int p, int l, int r){
        if(a <= l && r <= b){
            t[p] += c;
            add[p] += c;
            return;
        }
        int mid = getmid(l, r);
        push_down(p);
        if(a <= mid) update(a, b, c, p << 1, l, mid);
        if(b > mid)  update(a, b, c, p << 1|1, mid + 1, r);
        t[p] = max(t[p << 1], t[p << 1|1]);
    }
    T query(int a, int b, int p, int l, int r){
        if(a <= l && r <= b){
            return t[p];
        }
        int mid = getmid(l, r);
        push_down(p);
        T res = 0;
        if(a <= mid) res = max(res, query(a, b, p << 1, l, mid));
        if(b > mid)  res = max(res, query(a, b, p << 1|1, mid + 1, r));
        return res;
    }
};

SMT<ll> smt;

bool cmp(M a, M b){
    return a.x < b.x;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> P;
    REP(i, 1, n) cin >> A[i].FI >> A[i].SE;
    REP(i, 1, m){
        cin >> B[i] >> CB[i];
        if(C[B[i]] == 0) C[B[i]] = -CB[i];
        else C[B[i]] = max(C[B[i]], -CB[i]);
    }
    smt.build(1, 1, 1000 * 1000);
    sort(B + 1, B + m + 1);
    sort(A + 1, A + n + 1);
    REP(i, 1, P){
        cin >> mon[i].x >> mon[i].y >> mon[i].z;
    }
    sort(mon + 1, mon + P + 1, cmp);
    ll ans = -INF;
    int p = 0;
    REP(i, 1, n){
        while(p < P && A[i].FI > mon[p + 1].x){
            int pos = upper_bound(B + 1, B + m + 1, mon[p + 1].y) - B;
            if(pos <= m){
                smt.update(B[pos], 1000 * 1000, mon[p + 1].z, 1, 1, 1000 * 1000);
            }
            p++;
        }
        ans = max(ans, smt.t[1] - A[i].SE);
    }
    cout << ans << '\n';
    return 0;
}
