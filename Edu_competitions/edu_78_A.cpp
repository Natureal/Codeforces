#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define DEC(i, a, b) for(int i = b; i >= a; --i)
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

int t;
string a, b;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    for(int o = 1; o <= t; ++o){
        cin >> a >> b;
        map<int, int> mpa;
        REP(i, 0, SZ(a) - 1) mpa[a[i] - 'a']++;
        bool ans = false;
        REP(i, 0, SZ(b) - SZ(a)){
            map<int, int> mpb;
            REP(j, 0, SZ(a) - 1) mpb[b[i + j] - 'a']++;
            ans |= (mpa == mpb);
            if(ans) break;
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
