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

int t, n;
int p[400010];

int main(){
	cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> p[i];
        sort(p + 1, p + n + 1, greater<int>());
        int ans = 0, g = 0, s = 0, b = 0;
        int tmax = 0;
        for(int i = 1; i <= n; ++i){
            int j = i;
            while(j + 1 <= n && p[j + 1] == p[i]){
                j++;
            }
            i = j;
            if(j <= n / 2) tmax = j;
            else break;
        }
        for(int i = 1; i <= n; ++i){
            int j = i;
            while(j + 1 <= n && p[j + 1] == p[i]){
                j++;
            }
            g = j;
            if(s < j) s = j;
            while(s - g <= g){
                s = s + 1;
                if(s > n) break;
                int k = s;
                while(k + 1 <= n && p[k + 1] == p[s]){
                    k++;
                }
                s = k;
            }
            if(s - g <= g) break;
            if(tmax - s <= g) break;
            ans = tmax;
            s = s - g;
            b = tmax - s - g;
            break;
        }
        if(ans == 0) cout << "0 0 0" << endl;
        else   cout << g << " " << s << " " << b << endl;
    }
    
    return 0;
}
