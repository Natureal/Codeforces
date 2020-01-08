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

int n;
int c[100010][3], d[100010], q[100010];
VI G[100010], V;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 0, 2){
        REP(j, 1, n) cin >> c[j][i];
    }
    REP(i, 1, n - 1){
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
        G[a].PB(b);
        G[b].PB(a);
    }
    REP(i, 1, n) if(d[i] > 2){
        cout << -1 << endl;
        return 0;
    }
    int start, pre = -1;
    REP(i, 1, n) if(d[i] == 1){
        start = i;
        break;
    }
    while(1){
        V.PB(start);
        bool f = false;
        for(auto v: G[start]) if(v != pre){
            pre = start;
            start = v;
            f = true;
            break;
        }
        if(!f) break;
    }
    ll ans = (1LL << 62) - 1;
    VI ans_c;
    REP(i, 0, 2){
        REP(j, 0, 2) if(i != j){
            ll tmp = c[V[0]][i] + c[V[1]][j];
            VI tmp_c; tmp_c.PB(i); tmp_c.PB(j);
            int pre = j, prepre = i;
            REP(k, 2, SZ(V) - 1){
                int nxt = 3 ^ pre ^ prepre;
                tmp += c[V[k]][nxt];
                tmp_c.PB(nxt);
                prepre = pre;
                pre = nxt;
            }
            if(tmp < ans){
                ans = tmp;
                ans_c = tmp_c;
            }
        }
    }
    cout << ans << endl;
    REP(i, 0, SZ(V) - 1) q[V[i]] = ans_c[i] + 1;
    REP(i, 1, n) cout << q[i] << " ";
    cout << endl;
    return 0;
}
