// Submask DP
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
typedef vector<int> VI;
const int mod = 1000000007;

int k, n[16], tot;
pii a[16 * 5010];
map<int, int> G;
map<ll, int> vmap;
bool vis[16 * 5010], vis2[16];
ll sum[16];
int sta[1 << 15], dp[1 << 15], pre[1 << 15];
pii ans[16];

void Dfs(int p, int status, int root){
    //printf("p: %d\n", p);
    vis[p] = 1;
    vis2[a[p].SE] = 1;
    status |= (1 << (a[p].SE - 1));
    int v = G[p];
    if(v == root){
        sta[status] = root;
        //printf("p: %d, v: %d, root: %d\n", p, v, root);
    }       
    else if(v && !vis[v] && !vis2[a[v].SE]) Dfs(v, status, root);
    vis[p] = 0;
    vis2[a[p].SE] = 0;
}

void WD(int s){
    int p = sta[s], q = p;
    while(1){
        int nxt_q = G[q];
        //printf("q %d %d\n", q, nxt_q);
        ans[a[nxt_q].SE] = MP(a[nxt_q].FI, a[q].SE);
        q = nxt_q;
        if(q == p) break;
    }
}

bool Solve(){
    REP(i, 1, tot){
        Dfs(i, 0, i);
    }
    REP(i, 0, (1 << k) - 1) dp[i] = sta[i] > 0;
    for(int s = 0; s < (1 << k); ++s) if(!dp[s]){
        for(int d = s; d; d = (d - 1) & s){
            if(dp[d] && dp[s ^ d]){
                dp[s] = 1;
                pre[s] = d;
                break;
            }
        }
    }
    //REP(i, 0, (1 << k) - 1){
      //  printf("dp[%d] : %d, sta %d , pre: %d\n", i, dp[i], sta[i], pre[i]);
    //}
    if(!dp[(1 << k) - 1]) return false;
    else{
        cout << "Yes" << endl;
        stack<int> st;
        st.push((1 << k) - 1);
        while(!st.empty()){
            int s = st.top();
            st.pop();
            if(sta[s]){
                //printf("wd %d\n", s);
                WD(s);
            }
            else{
                st.push(pre[s]);
                st.push(s ^ pre[s]);
            }
        }
        REP(i, 1, k){
            cout << ans[i].FI << " " << ans[i].SE << endl;
        }
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> k;
    REP(i, 1, k){
        cin >> n[i];
        REP(j, 1, n[i]){
            ++tot;
            cin >> a[tot].FI;
            vmap[a[tot].FI] = tot;
            a[tot].SE = i;
            sum[i] += a[tot].FI;
        }
    }
    ll a_sum = 0;
    REP(i, 1, k) a_sum += sum[i];
    if(abs(a_sum) % k == 0){
        REP(i, 1, tot){
            ll dif = a_sum / k - sum[a[i].SE];
            ll need = dif + a[i].FI;
            //printf("i: %d, dif: %lld, need: %lld\n", i, dif, need);
            if(vmap[need]){
                //printf("edge: %d -> %d\n", i, vmap[need]);
                G[i] = vmap[need];
            }
        }
        if(!Solve()) cout << "No" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
