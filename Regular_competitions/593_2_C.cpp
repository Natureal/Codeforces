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
vector<int> g[310];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int id = 1, p = 1;
    DEC(i, n * n, 1){
        g[id].PB(i);
        id += p;
        if(id > n){
            id = n;
            p = -1;
        }
        if(id < 1){
            id = 1;
            p = 1;
        }
    }
    REP(i, 1, n){
        for(auto v: g[i]){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
