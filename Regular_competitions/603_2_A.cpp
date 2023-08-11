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


int main(){
	int s[3];
    int t;
    cin >> t;
    for(int q = 1; q <= t; ++q){
        cin >> s[0] >> s[1] >> s[2];
        sort(s, s + 3);
        int ans = 0;
        if(s[0] > s[2] - s[1]){
            ans += s[2] - s[1];
            s[0] -= s[2] - s[1];
            s[2] = s[1];
            ans += s[0] / 2 * 2;
            ans += s[1] - s[0] / 2;
        }
        else{
            ans = s[0] + s[1];
        }
        cout << ans << endl;
    }
    
    return 0;
}
