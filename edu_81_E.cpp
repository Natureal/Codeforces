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

int n, P[200010], A[200010], IA[200010], IP[200010];

// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = 200010;
ll t[maxn << 2], add[maxn << 2], init[maxn];

void build(int p, int l, int r){
    if(l == r){
        t[p] = init[l];
        return;
    }
    int mid = getmid(l, r);
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    t[p] = min(t[p << 1], t[p << 1|1]);
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

void update(int a, int b, int c, int p, int l, int r){
    if(a > b) return;
    if(a <= l && r <= b){
        t[p] += c;
        add[p] += c;
        return;
    }
    int mid = getmid(l, r);
    push_down(p);
    if(a <= mid) update(a, b, c, p << 1, l, mid);
    if(b > mid)  update(a, b, c, p << 1|1, mid + 1, r);
    t[p] = min(t[p << 1], t[p << 1|1]);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    ll p1;
    REP(i, 1, n) cin >> P[i], IP[P[i]] = i;
    REP(i, 1, n){
        cin >> A[i];
        IA[P[i]] = A[i];
    }
    ll sum = IA[1];
    REP(i, 1, n){
        if(P[i] == 1) sum -= A[i];
        else sum += A[i];
        init[i] = sum;
    }
    REP(i, 1, n){
        //printf("init[%d]: %d\n", i, init[i]);
    }
    build(1, 1, n - 1);
    ll ans = t[1];
    ans = min(ans, 1ll * A[1]);
    ans = min(ans, 1ll * A[n]);
    REP(i, 2, n){
        update(1, IP[i] - 1, IA[i], 1, 1, n - 1);
        update(IP[i], n - 1, -IA[i], 1, 1, n - 1);
       // printf("now: %d\n", i);
       // printf("+ %d %d, %d\n", 1, IP[i] - 1, IA[i]);
       // printf("- %d %d, %d\n", IP[i], n - 1, -IA[i]);
       // printf("t1: %lld\n", t[1]);
        ans = min(ans, t[1]);
    }
    cout << ans << endl;
    return 0;
}
