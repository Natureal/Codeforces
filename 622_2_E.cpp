// Z Function, SMT
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
const int maxn = 1000010;
const int tmaxn = 1000010;

template<class T>
struct SMT{
    T t[tmaxn << 2], add[tmaxn << 2];
    void clear(){
        MEM(t, 0);
        MEM(add, 0);
    }
    void push_down(int p, int l, int r){
        if(add[p]){
            int mid = getmid(l, r);
            t[p << 1] += add[p] * (mid - l + 1);
            add[p << 1] += add[p];
            t[p << 1|1] += add[p] * (r - mid);
            add[p << 1|1] += add[p];
            add[p] = 0;
        }
    }
    void update(int a, int b, T c, int p, int l, int r){
        if(a <= l && r <= b){
            t[p] += c * (r - l + 1);
            add[p] += c;
            return;
        }
        int mid = getmid(l, r);
        push_down(p, l, r);
        if(a <= mid) update(a, b, c, p << 1, l, mid);
        if(b > mid)  update(a, b, c, p << 1|1, mid + 1, r);
        t[p] = t[p << 1] + t[p << 1|1];
    }
    T query(int a, int b, int p, int l, int r){
        if(a <= l && r <= b){
            return t[p];
        }
        int mid = getmid(l, r);
        push_down(p, l, r);
        T res = 0;
        if(a <= mid) res += query(a, b, p << 1, l, mid);
        if(b > mid)  res += query(a, b, p << 1|1, mid + 1, r);
        return res;
    }
};

SMT<ll> smt;

int Z[maxn << 1], ZA[maxn], ZB[maxn];
char A[maxn], B[maxn], S[maxn << 1];
int n, m;

void Get_Z(char *s, int len = -1){
    // Z: length of matched prefix starting with i (index)
    int L = 0, R = 0;
    len = (len == -1) ? strlen(s + 1) : len;
    Z[1] = len;
    REP(i, 2, len){
        if(i > R){
            L = i, R = i - 1;
            while(R + 1 <= len && s[R - L + 2] == s[R + 1]) R++;
            Z[i] = R - L + 1;
        }
        else{
            int k = 1 + i - L;
            if(Z[k] < R - i + 1) Z[i] = Z[k];
            else{
                L = i;
                while(R + 1 <= len && s[R - L + 2] == s[R + 1]) R++;
                Z[i] = R - L + 1;
            }
        }
    }
}

void Z_match(int *ZX, char *s, char *ref, int len, int ref_len){
    int L = 0, R = 0;
    REP(i, 1, len){
        if(i > R){
            L = i, R = i - 1;
            while(R + 1 <= len && R - L + 2 <= ref_len && ref[R - L + 2] == s[R + 1]) R++;
            ZX[i] = R - L + 1;
        }
        else{
            int k = 1 + i - L;
            if(Z[k] < R - i + 1) ZX[i] = Z[k];
            else{
                L = i;
                while(R + 1 <= len && R - L + 2 <= ref_len && ref[R - L + 2] == s[R + 1]) R++;
                ZX[i] = R - L + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> A + 1 >> B + 1 >> S + 1;
    Get_Z(S, m);
    Z_match(ZA, A, S, n, m);

    reverse(B + 1, B + n + 1);
    reverse(S + 1, S + m + 1);
    Get_Z(S, m);
    Z_match(ZB, B, S, n, m);
    reverse(ZB + 1, ZB + n + 1);
    
    REP(i, 1, min(n, m - 1)){
        if(ZB[i]) smt.update(1, ZB[i], 1, 1, 1, m);
    }
    ll ans = (ZA[1] == 0) ? 0 : smt.query(max(1, m - ZA[1]), m - 1, 1, 1, m);
    REP(i, 2, n){
        if(ZB[i - 1]) smt.update(1, ZB[i - 1], -1, 1, 1, m);
        if(i + m - 2 <= n && ZB[i + m - 2]) smt.update(1, ZB[i + m - 2], 1, 1, 1, m);
        if(ZA[i]) ans += smt.query(max(1, m - ZA[i]), m - 1, 1, 1, m);
    }
    cout << ans << endl;
    REP(i, 1, n){
    //    printf("%d, ZA: %d, ZB: %d\n", i, ZA[i], ZB[i]);
    }
    return 0;
}
