#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): *(s.find_by_order(2), counting from 0)
// order_of_key(k) returns the number of items strictly smaller than item k.
template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, 
        tree_order_statistics_node_update>;

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

int n, q;
int a[100010];
pii pre[100010];
int precnt;
int que[100010], tot;
queue<int> Q;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> q;
    int tmax = -1;
    REP(i, 1, n){
        cin >> a[i];
        tmax = max(tmax, a[i]);
        Q.push(a[i]);
    }
    int cur = Q.front(); Q.pop();
    while(!Q.empty()){
        int a = Q.front(); Q.pop();
        pre[++precnt] = MP(cur, a);
        if(cur > a) que[tot++] = a;
        else{
            que[tot++] = cur;
            cur = a;
        }
    }
    REP(i, 1, q){
        ll m;
        cin >> m;
        if(m <= precnt) cout << pre[m].FI << " " << pre[m].SE << endl;
        else{
            int id = (int)((m - precnt - 1) % tot);
            cout << tmax << " " << que[id] << endl;
        }
    }
    return 0;
}
