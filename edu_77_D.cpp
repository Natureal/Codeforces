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

int n, m, k, t;
int a[200010];

struct Trap{
    int l, r, d;
}T[200010];

bool check(int v){
    int rmax = 0;
    vector<Trap> V;
    REP(i, 1, k) if(T[i].d > v) V.PB(T[i]);
    ll plus = 0;
    REP(i, 0, SZ(V) - 1){
        if(rmax >= V[i].l){
            plus += 2LL * max(0, V[i].r - rmax);
        }
        else{
            plus += 2LL * (V[i].r - V[i].l + 1);
        }
        rmax = max(rmax, V[i].r);
    }
    if(n + 1 + plus > t) return false;
    return true;
}

bool cmp(Trap A, Trap B){
    return A.l < B.l;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> m >> n >> k >> t;
    REP(i, 1, m) cin >> a[i];
    REP(i, 1, k){
        cin >> T[i].l >> T[i].r >> T[i].d;
    }
    sort(a + 1, a + m + 1, greater<int>());
    sort(T + 1, T + k + 1, cmp);
    int L = 0, R = m;
    while(L < R){
        int mid = getmid(L, R);
        if(check(a[mid])) L = mid + 1;
        else R = mid;
    }
    if(L && !check(a[L])) L--;
    cout << L << endl;
    return 0;
}
