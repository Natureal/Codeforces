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

int n, m;
char s[200010], t[200010];
int pre[26][200010], cur[26];

bool check(int p){
    REP(i, 0, 25){
        if(pre[i][p] < cur[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> s + 1;
    REP(i, 1, n){
        if(i > 1){
            REP(j, 0, 25) pre[j][i] = pre[j][i - 1];
        }
        pre[s[i] - 'a'][i]++;
    }
    cin >> m;
    REP(i, 1, m){
        cin >> t + 1;
        int len = strlen(t + 1);
        MEM(cur, 0);
        REP(j, 1, len) cur[t[j] - 'a']++;
        int l = 1, r = n;
        while(l < r){
            int mid = getmid(l, r);
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
