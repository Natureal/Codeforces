// Sparse graph search
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
const int mod = 1000000007;

int n, m;
set<int> st[100010];
set<int> rem, tmp;

const int maxn = 100010;
int col[maxn], num;

void Dfs(int p){
    col[p] = num;
    VI to_go;
    for(auto v: rem) if(st[p].find(v) == st[p].end()){
        to_go.PB(v);
    }
    for(auto v: to_go) rem.erase(v);
    for(auto v: to_go) Dfs(v);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
    REP(i, 1, m){
        int a, b;
        cin >> a >> b;
        st[a].insert(b);
        st[b].insert(a);
    }
    num = 0;
    REP(i, 1, n) rem.insert(i);
    REP(i, 1, n) if(!col[i]){
        ++num;
        if(num > 3) break;
        rem.erase(i);
        Dfs(i);
    }
    if(num != 3) cout << -1 << endl;
    else{
        bool ava = true;
        REP(i, 1, n){
            for(auto v: st[i]) if(col[i] == col[v]){
                ava = false;
                break;
            }
            if(!ava) break;
        }
        if(!ava){
            cout << -1 << endl;
            return 0;
        }
        REP(i, 1, n) cout << col[i] << " ";
        cout << endl;
    }
    return 0;
}
