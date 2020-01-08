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

// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = 30;

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

int q, n;
char s[2][200010], ts[2][200010];
BIT<int> B;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> q;
    REP(t, 1, q){
        cin >> n;
        cin >> s[0] >> s[1];
        memcpy(ts, s, sizeof(s));
        REP(i, 0, 1) sort(ts[i], ts[i] + n);
        bool f = true;
        REP(i, 0, n - 1) if(ts[0][i] != ts[1][i]){
            f = false;
            break;
        }
        if(f){
            bool ff = false;
            REP(i, 0, n - 2) if(ts[0][i] == ts[0][i + 1]){
                ff = true;
                break;
            }
            if(!ff){
                int cnt[2] = {0};
                REP(i, 0, 1){
                    B.clear();
                    DEC(j, n - 1, 0){
                        int id = s[i][j] - 'a' + 1;
                        cnt[i] += B.get(id - 1);
                        B.add(id, 1);
                    }
                }
                if(abs(cnt[0] - cnt[1]) % 2) f = false;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
