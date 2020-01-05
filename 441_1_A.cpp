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

int n;
int v[10][2];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 0, 9) v[i][1] = 1;
    REP(i, 1, n){
        char s[2];
        int a;
        cin >> s >> a;
        REP(j, 0, 9){
            if(s[0] == '|'){
                v[j][0] |= (a & (1 << j)) > 0;
                v[j][1] |= (a & (1 << j)) > 0;
            }   
            else if(s[0] == '&'){
                v[j][0] &= (a & (1 << j)) > 0;
                v[j][1] &= (a & (1 << j)) > 0;
            }
            else if(s[0] == '^'){
                v[j][0] ^= (a & (1 << j)) > 0;
                v[j][1] ^= (a & (1 << j)) > 0;
            }
        }
    }
    int ans_1 = 0, ans_2 = 1023, ans_3 = 0;
    REP(i, 0, 9){
        if(v[i][0] == 0 && v[i][1] == 0) ans_2 ^= (1 << i);
        if(v[i][0] == 1 && v[i][1] == 0) ans_3 |= (1 << i);
        if(v[i][0] == 1 && v[i][1] == 1) ans_1 |= (1 << i);
    }
    cout << 3 << endl;
    cout << '|' << " " << ans_1 << endl;
    cout << '&' << " " << ans_2 << endl;
    cout << '^' << " " << ans_3 << endl;
    return 0;
}
