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
	int n;
    ll A;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> A;
        if(A <= 14){
            cout << "NO" << endl;
            continue;
        }
        if(A % 14 > 0 && A % 14 < 7){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
