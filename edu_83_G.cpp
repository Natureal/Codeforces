#pragma GCC optimize("O3")
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
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
int ans[1000010], A[1000010], val[1000010];
int que[1000010], tot, L[1000010], R[1000010];
VPI G[1000010];

const int maxn = 1000010;

template<class T>
struct SMT{
    T t[maxn << 2], st[maxn << 2];
    void clear(){
        MEM(t, 0);
    }
    void push_down(int p){
	    if(st[p]){
		    st[p << 1] = min(st[p << 1], st[p]);
		    t[p << 1] = min(t[p << 1], st[p]);
		    st[p << 1|1] = min(st[p << 1|1], st[p]);
		    t[p << 1|1] = min(t[p << 1|1], st[p]);
		    st[p] = 0;
	    }
    }
    void update(int a, int b, T c, int p, int l, int r){
        if(a <= l && r <= b){
            t[p] = min(t[p], c);
	    st[p] = min(st[p], c);
            return;
        }
        int mid = getmid(l, r);
	push_down(p);
        if(a <= mid) update(a, b, c, p << 1, l, mid);
        if(b > mid)  update(a, b, c, p << 1|1, mid + 1, r);
        t[p] = min(t[p << 1], t[p << 1|1]);
    }
    T query(int a, int b, int p, int l, int r){
        if(a <= l && r <= b){
            return t[p];
        }
        int mid = getmid(l, r);
	push_down(p);
        T res = 0;
        if(a <= mid) res = min(res, query(a, b, p << 1, l, mid));
        if(b > mid)  res = min(res, query(a, b, p << 1|1, mid + 1, r));
        return res;
    }
};

SMT<int> smt;

void Dfs(int p){
    if(val[p]){
	    que[++tot] = p;
    }
    L[p] = tot + (val[p] == 0);
    REP(i, 0, SZ(G[p]) - 1){
        Dfs(G[p][i].SE);
    }
    R[p] = tot;
}

void Solve(int p, int num){
	if(val[p]){
		int res = smt.query(L[p], L[p], 1, 1, n);
		//cout << "p : " << p << " , res: " << res << endl;
		ans[p] = min(num, res + L[p]);
		num = min(num, ans[p]);
	}
		int now = num + 1 - L[p];
		if(now < 0 && R[p] >= L[p]) smt.update(L[p], R[p], now, 1, 1, n);
	//cout << "p: " << p << ", num: " << num << ", now: " << now << " lr: " << L[p] << " , " << R[p] << endl;
	
	REP(i, 0, SZ(G[p]) - 1){
		Solve(G[p][i].SE, num + 1);
	}
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    int tmax = 0;
    REP(i, 1, n){
        int p;
        char s[2];
        cin >> p >> s;
        G[p].PB(MP(s[0] - 'a', i));
        tmax = max(tmax, p);
    }
    REP(i, 0, tmax) sort(G[i].begin(), G[i].end());
    int K;
    cin >> K;
    REP(i, 1, K){
        cin >> A[i];
        val[A[i]] = 1;
    }
    Dfs(0);
    Solve(0, 0);
    REP(i, 1, K){
        cout << ans[A[i]] << " ";
    }
    cout << '\n';
    return 0;
}

