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

int T, r, c, k;
char g[110][110];
char to_be[62];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> T;
    REP(q, 1, T){
        cin >> r >> c >> k;
        int sum = 0;
        REP(i, 0, r - 1){
            cin >> g[i];
            REP(j, 0, c - 1) if(g[i][j] == 'R') sum++;
        }
        int num = sum / k;
        int rem = sum % k;
        int dir[2] = {0, 1};
        int x = 0, y = 0, tot = 0, cur = 0;
        while(1){
            //cout << x << " " << y << endl;
            if(g[x][y] == 'R'){
                if((rem && cur == num + 1) || (!rem && cur == num)){
                    if(cur == num + 1) rem--;
                    tot++;
                    cur = 0;
                }
                cur++;
            }
            if(tot < 26) g[x][y] = tot + 'a';
            else if(tot < 52) g[x][y] = tot - 26 + 'A';
            else g[x][y] = tot - 52 + '0';
            y += dir[1];
            if(y >= c){
                x++;
                y = c - 1;
                dir[1] = -1;
            }
            if(y < 0){
                x++;
                y = 0;
                dir[1] = 1;
            }
            if(x >= r) break;
        }
        REP(i, 0, r - 1) cout << g[i] << endl;
    }
    return 0;
}
