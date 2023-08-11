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
const int mod = 1000000007;

int n, k;
string s, t;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
    cin >> s;
    t = s.substr(0, k);
    REP(i, k, n - 1) t += t[i - k];
    cout << n << endl;
    if(t >= s){
        cout << t << endl;
    }
    else{
        DEC(i, k - 1, 0){
            if(t[i] == '9'){
                t[i] = '0';
            }
            else{
                t[i]++;
                break;
            }
        }
        REP(i, k, n - 1) t[i] = t[i - k];
        cout << t << endl;
    }
    return 0;
}
