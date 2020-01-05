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

set<int> r_st[100010], c_st[100010];
int n, m, k;

bool Solve(int v1, int v2){
    int x = 1, y = 1, up = 0, right = 0, left = 0, bot = 0;
    int d[2] = {v1, v2};
    ll L = 0;
    while(1){
        //printf("x y %d %d\n", x, y);
        int nx, ny;
        if(d[1] == 1){
            // right
            nx = x;
            ny = m - right;
            if(!r_st[x].empty()){
                auto it = r_st[x].lower_bound(y);
                if(it != r_st[x].end()){
                    ny = min(ny, (*it) - 1);
                }
            }
            L += (ny - y);
            up = x;
            d[0] = 1; d[1] = 0;
            //printf("r %d %d\n", nx, ny);
        }
        else if(d[0] == 1){
            // down
            nx = n - bot;
            ny = y;
            if(!c_st[y].empty()){
                auto it = c_st[y].lower_bound(x);
                if(it != c_st[y].end()){
                    nx = min(nx, (*it) - 1);
                }
            }
            L += (nx - x);
            right = m - y + 1;
            d[0] = 0; d[1] = -1;
            //printf("d %d %d\n", nx, ny);
        }
        else if(d[1] == -1){
            // left
            nx = x;
            ny = left + 1;
            if(!r_st[x].empty()){
                auto it = r_st[x].lower_bound(y);
                if(it != r_st[x].begin()){
                    it--;
                    ny = max(ny, (*it) + 1);
                }
            }
            L += (y - ny);
            bot = n - x + 1;
            d[0] = -1; d[1] = 0;
            //printf("l %d %d\n", nx, ny);
        }
        else if(d[0] == -1){
            // up
            nx = up + 1;
            ny = y;
            if(!c_st[y].empty()){
                auto it = c_st[y].lower_bound(x);
                if(it != c_st[y].begin()){
                    it--;
                    nx = max(nx, (*it) + 1);
                }
            }
            L += (x - nx);
            left = y;
            d[0] = 0; d[1] = 1;
            //printf("u %d %d\n", nx, ny);
        }
        if(x == nx && y == ny) break;
        x = nx;
        y = ny;
    }
    return L == 1LL * n * m - k - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
    REP(i, 1, k){
        int a, b;
        cin >> a >> b;
        r_st[a].insert(b);
        c_st[b].insert(a);
    }
    if(Solve(0, 1) || Solve(1, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
