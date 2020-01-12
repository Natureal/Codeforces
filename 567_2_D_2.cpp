#include <bits/stdc++.h>
using namespace std;

// Common file for tree<>
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Operation 1: find_by_order(k) returns an iterator to kth (counting from 0) element. (You need dereference it, like *(s.find_by_order(2))
// Operation 2: order_of_key(k) returns the number of items strictly smaller than item k.
// type_of_data, null_means_set, comparison, type_of_tree_used, support_updating_node_variants
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

int n, m, q, num[500010];
pll Q[500010];
map<int, int> mp;
vector<int> VP[500010];
vector<pii > V;
int ans[500010];
ordered_set o_st;

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
        for(auto v: VP[V[i].FI]) o_st.insert(v);
        cur_num += V[i].SE;
        if(i < SZ(V) - 1){
            top = 1LL * (V[i + 1].FI - V[i].FI) * cur_num;
        }
        while(p <= q && Q[p].FI <= sum + top){
            Q[p].FI -= sum;
            int sz = o_st.size();
            ans[Q[p].SE] = *o_st.find_by_order((Q[p].FI - 1) % sz);
            p++;
        }
        sum += top;
    }
    REP(i, 1, q) cout << ans[i] << endl;
    return 0;
}
