#pragma GCC optimize("O3")
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
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;

int g[51][51];
int dir[8][2] = {{0, 2}, {0, 2}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {2, 0}, {2, 0}};
int dir1[8][2] = {{0, 1}, {0, 1}, {0, 1}, {1, 0}, {0, 1}, {1, 0}, {1, 0}, {1, 0}};
int dir2[8][2] = {{0, 3}, {1, 2}, {2, 1}, {2, 1}, {1, 2}, {1, 2}, {2, 1}, {3, 0}};
int n;

int Q(int a1, int b1, int a2, int b2){
    cout << "? " << a1 << " " << b1 << " " << a2 << " " << b2 << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    g[1][1] = 1;
    g[1][2] = 0;
    g[n][n] = 0;
    REP(i, 1, n){
        if(i & 1){
            if(i > 1) g[i][1] = g[i - 2][1] ^ 1 ^ Q(i - 2, 1, i, 1);
            if(i > 1) g[i][2] = g[i - 1][1] ^ 1 ^ Q(i - 1, 1, i, 2);
            REP(j, 3, (i == n ? n - 1 : n)) g[i][j] = g[i][j - 2] ^ 1 ^ Q(i, j - 2, i, j);
        }
        else{
            g[i][2] = g[i - 1][1] ^ 1 ^ Q(i - 1, 1, i, 2);
            for(int j = 4; j <= n; j += 2) g[i][j] = g[i][j - 2] ^ 1 ^ Q(i, j - 2, i, j);
            g[i][n] = g[i - 1][n - 1] ^ 1 ^ Q(i - 1, n - 1, i, n);
            for(int j = n - 2; j >= 1; j -= 2) g[i][j] = g[i][j + 2] ^ 1 ^ Q(i, j, i, j + 2);
        }
    }
    bool flip = false;
    bool find = false;
    REP(i, 1, n){
        REP(j, 1, n){
            REP(k, 0, 7){
                int ti = i + dir[k][0], tj = j + dir[k][1];
                int ai = i + dir1[k][0], aj = j + dir1[k][1];
                int bi = i + dir2[k][0], bj = j + dir2[k][1];
                if(ti > n || tj > n || ai > n || aj > n || bi > n || bj > n) continue;
                if((g[i][j] == g[ti][tj] && g[ai][aj] == g[bi][bj]) ||
                   (g[i][j] != g[ti][tj] && g[ai][aj] != g[bi][bj])){
                    //cout << "ij " << i << " " << j << endl;
                    //cout << "tij" << ti << " " << tj << endl;
                    //cout << "aij " << ai << " " << aj << endl;
                    //cout << "bij " << bi << " " << bj << endl;
                    cout << "? " << i << " " << j << " " << bi << " " << bj << '\n';
                    cout.flush();
                    int res;
                    cin >> res;
                    int ans = g[i][j] ^ res ^ 1;
                    if(ans != g[bi][bj]) flip = true;
                    find = true;
                }
                if(find) break;
            }
            if(find) break;
        }
        if(find) break;
    }
    if(flip){
        REP(i, 1, n){
            REP(j, 1, n){
                if((i + j) % 2 == 1){
                    g[i][j] ^= 1;
                }
            }
        }
    }
    cout << "!" << '\n';
    cout.flush();
    REP(i, 1, n){
        REP(j, 1, n){
            cout << g[i][j];
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
