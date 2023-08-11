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

int n, m;
map<int, int> mp[100010];
bool vis[100010];
int fa[100010];

int find(int x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, n) fa[i] = i;
    REP(i, 1, m){
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    REP(i, 1, n) if(!vis[i]){
        vis[i] = 1;
        map<int, int> tmap = mp[i], nxt_tmap;
        while(1){
          //  printf("--\n");
            int j_cnt = 0;
            map<int, int> cnt;
            REP(j, 1, n) if(!vis[j] && !tmap[j]){
                vis[j] = 1;
                int x = find(i), y = find(j);
                if(x != y){
                    j_cnt++;
                    fa[y] = x;
                   // printf("--> %d %d\n", i, j);
                }
                for(auto it: mp[j]) if(!vis[it.FI]){
                    cnt[it.FI]++;
                }
            }
            nxt_tmap = tmap;
            for(auto it: tmap) if(!vis[it.FI]){
                if(cnt[it.FI] != j_cnt){
                    nxt_tmap[it.FI] = 0;
                }
            }
            tmap = nxt_tmap;
            if(!j_cnt) break;
        }
    }
    int num = 0;
    REP(i, 1, n) if(fa[i] == i) num++;
    cout << num - 1 << endl;
    return 0;
}
