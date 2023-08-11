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

int a, b, c, d;

int main(){
	cin >> a >> b >> c >> d;
    if(a > b + 1 || d > c + 1){
        cout << "NO" << endl;
        return 0;
    }
    int f1 = 0, f2 = 0;
    if(a == b + 1){
        f1 = 1;
        if(c == 0 && d == 0){
            cout << "YES" << endl;
            cout << "0 ";
            for(int i = 1; i <= b; ++i) cout << "1 0 ";
            cout << endl;
            return 0;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    else{
        b -= a;
    }
    if(d == c + 1){
        f2 = 1;
        if(a == 0 && b == 0){
            cout << "YES" << endl;
            cout << "3 ";
            for(int i = 1; i <= c; ++i) cout << "2 3 ";
            cout << endl;
            return 0;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    else{
        c -= d;
    }
    int pair = min(b, c);
    b -= pair;
    c -= pair;
    if(b > 1 || c > 1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(b) cout << "1 ";
    for(int i = 1; i <= a; ++i) cout << "0 1 ";
    for(int i = 1; i <= pair; ++i) cout << "2 1 ";
    for(int i = 1; i <= d; ++i) cout << "2 3 ";
    if(c) cout << "2 ";
    cout << endl;
    return 0;
}
