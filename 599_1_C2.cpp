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

int k, n[16], a[16][5010];
ll sum[16], all_sum;
map<ll, pii > mp;
map<pii, pii > G;
bool vis[16];
int sta[1 << 15], pre[1 << 15], ans[16][2];

void Dfs(int x, int y, int stx, int sty, int status){
    if(vis[x]){
        if(x == stx && y == sty)
            sta[status] = stx * 10000 + sty;
        return;
    }
    vis[x] = 1;
    if(G.find(MP(x, y)) != G.end()){
        pii nxt = G[MP(x, y)];
        Dfs(nxt.FI, nxt.SE, stx, sty, status | (1 << x - 1));
    }
    vis[x] = 0;
}

void Solve(){
    REP(i, 1, k){
        REP(j, 1, n[i]){
            Dfs(i, j, i, j, 0);
        }
    }
    for(int s = 0; s < (1 << k); ++ s) if(!sta[s]){
        for(int d = s; d; d = (d - 1) & s){
            if(sta[d] && sta[s ^ d]){
                sta[s] = 1;
                pre[s] = d;
                break;
            }
        }
    }
    if(sta[(1 << k) - 1] == 0) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        stack<int> st; st.push((1 << k) - 1);
        while(!st.empty()){
            int s = st.top(); st.pop();
            if(pre[s] == 0){
                int x = sta[s] / 10000, y = sta[s] % 10000;
                int tx = x, ty = y;
                while(1){
                    pii tmp = G[MP(tx, ty)];
                    ans[tmp.FI][0] = a[tmp.FI][tmp.SE];
                    ans[tmp.FI][1] = tx;
                    tx = tmp.FI;
                    ty = tmp.SE;
                    if(tx == x && ty == y) break;
                }
                continue;
            }
            st.push(pre[s]);
            st.push(s ^ pre[s]);
        }
        REP(i, 1, k){
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> k;
    REP(i, 1, k){
        cin >> n[i];
        REP(j, 1, n[i]){
            cin >> a[i][j];
            sum[i] += a[i][j];
            mp[a[i][j]] = MP(i, j);
        }
        all_sum += sum[i];
    }
    if(all_sum % k){
        cout << "No" << endl;
    }
    else{
        REP(i, 1, k){
            ll dif = all_sum / k - sum[i];
            REP(j, 1, n[i]){
                ll need = a[i][j] + dif;
                if(mp.find(need) != mp.end()){
                    G[MP(i, j)] = mp[need];
                }
            }
        }
        Solve();
    }
    return 0;
}
