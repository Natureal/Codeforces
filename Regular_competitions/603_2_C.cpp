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
vector<int> V, ans;

int main(){
    cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        cin >> n;
        V.clear();
        ans.clear();
        V.PB(0);
        V.PB(n);
        for(int i = 1; 1LL * i * i <= n; ++i){
            V.PB(n / (n / i));
            V.PB(n / i);
        }
        sort(V.begin(), V.end());
        for(int i = 0; i < V.size(); ++i){
            if(i && V[i] == V[i - 1]) continue;
            ans.PB(V[i]);
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
