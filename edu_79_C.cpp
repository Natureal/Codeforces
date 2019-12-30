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
typedef pair<int,int> pii;
const int mod = 1000000007;

int t, n, m;
int a[100010], pa[100010];
int c[100010];

int Lowbit(int x){
    return x & (-x);
}

int Get(int x){
    int res = 0;
    while(x){
        res += c[x];
        x -= Lowbit(x);
    }
    return res;
}

void Update(int x, int d){
    while(x <= n){
        c[x] += d;
        x += Lowbit(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        MEM(c, 0);
        cin >> n >> m;
        REP(i, 1, n){
            cin >> a[i], pa[a[i]] = i;
            Update(i, 1);
        }
        ll ans = 0;
        int tmax = 0;
        REP(i, 1, m){
            int b;
            cin >> b;
            if(tmax > pa[b]){
                ans += 1;
            }
            else{
                tmax = pa[b];
                //printf("%d, Get %d : %d\n", pa[b] - 1, Get(pa[b] - 1));
                ans += 2 * Get(pa[b] - 1) + 1;
            }
            Update(pa[b], -1);
            //printf("%d : %lld\n", i, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
