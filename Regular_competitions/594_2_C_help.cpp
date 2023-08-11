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

int g[100][100], n, m;
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool check(){
    REP(i, 1, n){
        REP(j, 1, m){
            int c = 0;
            REP(k, 0, 3){
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if(ni < 1 || nj < 1 || ni > n || nj > m) continue;
                if(g[i][j] == g[ni][nj]) c++;
            }
            if(c >= 2) return false;
        }
    }
    return true;
}

void Print(){
    if(!check()) return;
    ans++;
    return;
    REP(i, 1, n){
        REP(j, 1, m){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << " ----- " << endl;
}

void Dfs(int a, int b){
    if(a == n + 1){
        Print();
        return;
    }
    int na = a, nb = b + 1;
    if(nb > m){
        na++;
        nb = 1;
    }
    g[a][b] = 0;
    if(g[a - 1][b] == 0 && g[a][b - 1] == 0);
    else Dfs(na, nb);
    g[a][b] = 1;
    if(g[a - 1][b] == 1 && g[a][b - 1] == 1);
    else Dfs(na, nb);
    g[a][b] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    REP(i, 7, 8){
        REP(j, 7, 8){
            MEM(g, -1);
            n = i, m = j;
            ans = 0;
            Dfs(1, 1);
            cout << i << " " << j << " -> " << ans << endl;
        }
    }
    return 0;
}
