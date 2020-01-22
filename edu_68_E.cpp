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

int n;

// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = 5010;

template<class T>
struct BIT{
    T c[maxn];
    BIT(){ clear(); }
    inline void clear(){ memset(c, 0, sizeof(c)); }
    inline T lowbit(T &x){ return x & (-x); }
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

BIT<int> bt[5010];

pair<int, pii> h[5010], v[5010];
int th, tv;
int hash_x[10010], hash_y[10010], idx[100010], idy[100010];
int tot_x, tot_y;

bool cmp(pair<int, pii> A, pair<int, pii> B){
    return A.SE.FI < B.SE.FI; 
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        a1 += 5002, b1 += 5002, a2 += 5002, b2 += 5002;
        if(a1 == a2){
            // ver
            if(b1 > b2) swap(b1, b2);
            v[++tv] = MP(a1, MP(b1, b2)); // x, y1, y2
        }
        else if(b1 == b2){
            // hor
            if(a1 > a2) swap(a1, a2);
            h[++th] = MP(b1, MP(a1, a2)); // y, x1, x2
            hash_y[++tot_y] = b1;
            hash_x[++tot_x] = a2;
        }
    }
    sort(v + 1, v + tv + 1);
    sort(h + 1, h + th + 1, cmp);
    sort(hash_x + 1, hash_x + tot_x + 1);
    sort(hash_y + 1, hash_y + tot_y + 1);
    tot_x = unique(hash_x + 1, hash_x + tot_x + 1) - hash_x - 1;
    tot_y = unique(hash_y + 1, hash_y + tot_y + 1) - hash_y - 1;
    REP(i, 1, tot_x) idx[hash_x[i]] = i;//, printf("x %d : %d\n", i, hash_x[i]);
    REP(i, 1, tot_y) idy[hash_y[i]] = i;//, printf("y %d : %d\n", i, hash_y[i]);
    int p = 0;
    ll ans = 0;
    REP(i, 1, tv){
        while(p + 1 <= th && h[p + 1].SE.FI <= v[i].FI){
            int id = idx[h[p + 1].SE.SE];
            REP(k, 1, id) bt[k].add(idy[h[p + 1].FI], 1);
            //printf("%d -> cai yong: %d %d %d, add: %d, id: %d -> %d\n", i, h[p + 1].FI - 5002, h[p + 1].SE.FI
                  //  - 5002, h[p + 1].SE.SE - 5002, idy[h[p + 1].FI], 1, id);
            p++;
        }
        REP(j, i + 1, tv) if(v[j].FI > v[i].FI){
            // vi, vj
            int ydown = max(v[i].SE.FI, v[j].SE.FI);
            int yup   = min(v[i].SE.SE, v[j].SE.SE);
            if(ydown <= yup){
                int pdown = lower_bound(hash_y + 1, hash_y + tot_y + 1, ydown) - hash_y;
                int pup   = upper_bound(hash_y + 1, hash_y + tot_y + 1, yup) - hash_y - 1;
                if(pdown <= pup){
                    int xdown = lower_bound(hash_x + 1, hash_x + tot_x + 1, v[j].FI) - hash_x;
                    int cnt = bt[xdown].get(pup) - bt[xdown].get(pdown - 1)
                            + bt[xdown - 1].get(pup) - bt[xdown - 1].get(pdown - 1);
                    //printf("ij: %d %d, pdown: %d, pup: %d, xdown: %d, cnt: %d\n", i, j, pdown, pup, xdown, cnt);
                    //printf("1: %d , 2: %d\n", bt[tot_x].get(pup) - bt[tot_x].get(pdown - 1),
                      //      bt[xdown - 1].get(pup) - bt[xdown - 1].get(pdown - 1));
                    if(cnt > 0) ans += 1LL * cnt * (cnt - 1);
                }
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
