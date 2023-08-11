#include <bits/stdc++.h>
#include <bitset>
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
typedef vector<int> VI;
const int mod = 1000000007;

int n;
pii ED[2][100010], ST[2][100010];
int mp_ed[100010], mp_st[100010];
int PRE[100010], SUF[100010], c[100010];

int Lowbit(int x){ return x & (-x); }

void Update(int x, int d){
    while(x <= n){
        c[x] = max(c[x], d);
        x += Lowbit(x);
    }
}

int Getmax(int x){
    int res = 0;
    while(x){
        res = max(res, c[x]);
        x -= Lowbit(x);
    }
    return res;
}

bool Solve(int u, int v){
    REP(i, 1, n){
        mp_ed[ED[u][i].SE] = i;
        mp_st[ST[u][i].SE] = i;
    }
    int pre = 0;
    REP(i, 1, n){
        while(pre + 1 <= n && ED[u][pre + 1].FI < ST[u][i].FI) pre++;
        PRE[ST[u][i].SE] = pre;
    }
    int suf = n + 1;
    DEC(i, n, 1){
        while(suf - 1 >= 1 && ST[u][suf - 1].FI > ED[u][i].FI) suf--;
        SUF[ED[u][i].SE] = suf;
    }
    MEM(c, 0);
    pre = 0;
    REP(i, 1, n){
        int cur_id = ST[v][i].SE;
        while(pre + 1 <= n && ED[v][pre + 1].FI < ST[v][i].FI){
            int id = ED[v][pre + 1].SE; 
            Update(mp_st[id], mp_ed[id]);
            pre++;
        }
        if(Getmax(SUF[cur_id] - 1) > PRE[cur_id]) return false;
    }
    MEM(c, 0);
    suf = n + 1;
    DEC(i, n, 1){
        int cur_id = ED[v][i].SE;
        while(suf - 1 >= 1 && ST[v][suf - 1].FI > ED[v][i].FI){
            int id = ST[v][suf - 1].SE;
            Update(mp_st[id], mp_ed[id]);
            suf--;
        }
        if(Getmax(SUF[cur_id] - 1) > PRE[cur_id]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        ED[0][i] = MP(b1, i); ED[1][i] = MP(b2, i);
        ST[0][i] = MP(a1, i); ST[1][i] = MP(a2, i);
    }
    REP(i, 0, 1) sort(ED[i] + 1, ED[i] + n + 1), sort(ST[i] + 1, ST[i] + n + 1);
    bool f = Solve(0, 1) & Solve(1, 0);
    if(!f) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
