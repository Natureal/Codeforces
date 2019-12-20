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
const int maxn = 1000010;

int n;
int ed[maxn], st[maxn], fa[maxn];

int Find(int x){ return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x != y) fa[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        int a, b;
        cin >> a >> b;
        ed[b] = a;
        st[a] = i;
        fa[i] = i;
    }
    stack<int> sta;
    int edgen = 0;
    REP(i, 1, 2 * n){
        if(edgen >= n) break;
        if(ed[i]){
            int id = st[ed[i]];
            stack<int> tmp;
            while(!sta.empty()){
                int x = sta.top(); sta.pop();
                if(x == ed[i]) break;
                tmp.push(x);
                Union(id, st[x]);
                edgen++;
            }
            while(!tmp.empty()){
                sta.push(tmp.top());
                tmp.pop();
            }
        }
        else sta.push(i);
    }
    int setn = 0;
    REP(i, 1, n) setn += fa[i] == i;
    if(setn == 1 && edgen == n - 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
