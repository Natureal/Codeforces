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
#define MT make_tuple
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1000000007;

int t, n;
int num[100010];
bool vis[100010];
map<pii, int> inner;
vector<int> G[100010];

void add_edge(int a, int b){
    G[a].PB(b);
    G[b].PB(a);
}

void Dfs(int p, int pre){
    cout << p << " ";
    vis[p] = true;
    for(auto v: G[p]) if(v != pre && !vis[v]){
        if(inner[MP(p, v)] == 0)
            Dfs(v, p);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        MEM(num, 0);
        MEM(vis, 0);
        map<int, set<tuple<int, int, int> > > mp;
        inner.clear();
        REP(i, 1, n) G[i].clear();
        REP(i, 1, n - 2){
            int v[3];
            cin >> v[0] >> v[1] >> v[2];
            sort(v, v + 3);
            mp[v[0]].insert(MT(v[1], v[2], i));
            mp[v[1]].insert(MT(v[0], v[2], i));
            mp[v[2]].insert(MT(v[0], v[1], i));
            num[v[0]]++;
            num[v[1]]++;
            num[v[2]]++;
        }
        vector<int> to_do;
        REP(i, 1, n){
            if(num[i] == 1) to_do.PB(i);
        }
        vector<int> ans_tri;
        int w = n;
        while(1){
            vector<int> tmp;
            for(auto v: to_do){
                for(auto it: mp[v]){
                    // tri: v, it.FI, it.SE
                    int u1 = get<0>(it), u2 = get<1>(it), id = get<2>(it);
                    //printf("w : %d, v: %d %d %d\n", w, v, u1, u2);
                    mp[u1].erase(MT(min(v, u2), max(v, u2), id));
                    mp[u2].erase(MT(min(v, u1), max(v, u1), id));
                    ans_tri.PB(id);
                    add_edge(v, u1);
                    add_edge(v, u2);
                    inner[MP(u1, u2)] = 1;
                    inner[MP(u2, u1)] = 1;
                    num[u1]--;
                    num[u2]--;
                    if(w != 3 && num[u1] == 1) tmp.PB(u1);
                    if(w != 3 && num[u2] == 1) tmp.PB(u2);
                }
                w--;
                if(w < 3) break;
            }
            to_do = tmp;
            if(w < 3) break;
        }
        Dfs(1, -1);
        cout << endl;
        for(auto v: ans_tri){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
