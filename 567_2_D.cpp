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
const int INF = (1 << 30) - 1;
const int mod = 1000000007;
const int maxn = 500010;

struct Treap{
    int root,tcnt;
    int key[maxn], pro[maxn], son[maxn][2], cnt[maxn], sz[maxn];
    void clear(){
        root = 0;
        tcnt = 0;
        pro[0] = INF;
        sz[0] = 0;
    }
    void update(int x){
        sz[x] = cnt[x] + sz[son[x][0]] + sz[son[x][1]];
    }
    void rotate(int &x,int t){
        int y = son[x][t];
        son[x][t] = son[y][1 - t];
        son[y][1 - t] = x;
        update(x);
        update(y);
        x = y;
    }
    void _insert(int &x,int k){
        if(x){ // non-empty subtree
            if(key[x] == k) ++cnt[x];
            else{
                int t = k > key[x];
                _insert(son[x][t],k);
                if(pro[son[x][t]] < pro[x]) rotate(x,t);
            }
        }
        else{ // empty subtree
            x = ++tcnt;
            cnt[x] = 1;
            key[x] = k;
            pro[x] = rand();
        }
        update(x);
    }
    void _erase(int &x,int k){
        if(key[x] == k){
            if(cnt[x] > 1) cnt[x]--;
            else{
                if(!son[x][0] && !son[x][1]){
                    x = 0;
                    return;
                }
                int t = pro[son[x][0]] > pro[son[x][1]];
                rotate(x,t);
                _erase(x,k);
            }
        }
        else _erase(son[x][k > key[x]],k);
    }
    int _get_kth(int &x,int k){
        if(sz[son[x][0]] >= k)
            return _get_kth(son[x][0],k);
        k -= cnt[x] + sz[son[x][0]];
        if(k <= 0) return key[x];
        return _get_kth(son[x][1],k);
    }
    void insert(int k){
        _insert(root,k);
    }
    void erase(int k){
        _erase(root,k);
    }
    int get_kth(int k){
        return _get_kth(root,k);
    }
    int size(){
        return sz[root];
    }
}tp;

int n, m, q, num[500010];
pll Q[500010];
map<int, int> mp;
vector<int> VP[500010];
vector<pii > V;
int ans[500010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
    REP(i, 1, n){
        int a;
        cin >> a;
        num[a]++;
    }
    REP(i, 1, q){
        cin >> Q[i].FI;
        Q[i].SE = i;
    }
    sort(Q + 1, Q + q + 1);
    REP(i, 1, m){
        mp[num[i]]++;
        VP[num[i]].PB(i);
    }
    for(auto it: mp){
        V.PB(it);
    }
    int p = 1;
    ll sum = n, cur_num = 0;
    REP(i, 0, SZ(V) - 1){
        ll top = (1LL << 62) - 1;
        for(auto v: VP[V[i].FI]) tp.insert(v);
        cur_num += V[i].SE;
        if(i < SZ(V) - 1){
            top = 1LL * (V[i + 1].FI - V[i].FI) * cur_num;
        }
        while(p <= q && Q[p].FI <= sum + top){
            Q[p].FI -= sum;
            int sz = tp.size();
            ans[Q[p].SE] = tp.get_kth((Q[p].FI - 1) % sz + 1);
            p++;
        }
        sum += top;
    }
    REP(i, 1, q) cout << ans[i] << endl;
    return 0;
}
