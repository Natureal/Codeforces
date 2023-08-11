#include <bits/stdc++.h>
using namespace std;
 
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;

int t;

int main(){
	cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        string s[11];
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            cin >> s[i];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j) continue;
                if(s[i] == s[j]){
                    ans++;
                    // change
                    bool f = false;
                    for(int o = 0; !f && o < 4; ++o){
                        for(int p = 0; !f && p < 10; ++p){
                            int tmp = s[i][o];
                            if(tmp == '0' + p) continue;
                            s[i][o] = '0' + p;
                            bool ok = true;
                            for(int k = 1; k <= n; ++k){
                                if(i == k) continue;
                                if(s[i] == s[k]){
                                    ok = false;
                                    break;
                                }
                            }
                            if(ok){
                                f = true;
                                break;
                            }
                            s[i][o] = tmp;
                        }
                    }
                    break;
                }
            }
        }
        cout << ans << endl;
        for(int i = 1; i <= n; ++i) cout << s[i] << endl;
    }
    
    return 0;
}
