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

char S[3][2010];
int avai[3][3][2010], len[3];

bool judge(int a, int b, int k){
    REP(i, k, min(len[a], k + len[b] - 1)){
        if(S[a][i] != '?' && S[b][i - k + 1] != '?' &&
                S[a][i] != S[b][i - k + 1]) return false;
    }
    return true;
}

int cal(int a, int b, int c){
    int res = 1 << 30;
    REP(i, 1, len[a]) if(avai[a][b][i]){
        // matched start point for b
        int top = max(len[a], i + len[b] - 1);
        REP(j, i, top){
            // matched start point for c
            if(j <= len[a] && avai[a][c][j] == 0) continue;
            if(j <= i + len[b] - 1 && avai[b][c][j - i + 1] == 0) continue;
            res = min(res, max(top, j + len[c] - 1));
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> S[0] + 1 >> S[1] + 1 >> S[2] + 1;
    REP(i, 0, 2) len[i] = strlen(S[i] + 1);
    REP(i, 0, 2){
        REP(j, 0, 2) if(i != j){
            REP(k, 1, len[i]){
                // si con sj
                avai[i][j][k] = judge(i, j, k);
            }
        }
    }
    int ans = len[0] + len[1] + len[2];
    int arr[3] = {0, 1, 2};
    do{
        ans = min(ans, cal(arr[0], arr[1], arr[2]));
    }while(next_permutation(arr, arr + 3));
    cout << ans << endl;
    return 0;
}
