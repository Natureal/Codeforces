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

int r, c;

int main(){
	cin >> r >> c;
    if(r == 1 && c == 1){
        cout << 0 << endl;
        return 0;
    }
    if(c >= r){
    for(int j = 1; j <= c; ++j){
        cout << j + 1 << " ";
    }
    cout << endl;
    for(int i = 2; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cout << (c + i) * (j + 1) << " ";
        }
        cout << endl;
    }
    }
    else{
        for(int i = 1; i <= r; ++i){
            cout << i + 1 << " ";
            for(int j = 2; j <= c; ++j){
                cout << (i + 1) * (r + j) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
