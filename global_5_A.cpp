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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;
const int mod = 1000000007;

int n, a[20010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int f = 0;
    REP(i, 1, n){
        cin >> a[i];
        if(a[i] % 2){
            if(a[i] > 0) f++;
            else f--;
        }
    }
    REP(i, 1, n){
        if(a[i] % 2 == 0) cout << a[i] / 2 << endl;
        else{
            if(a[i] > 0){
                cout << a[i] / 2 + (f > 0) << endl;
                if(f > 0) f -= 2;
            }
            if(a[i] < 0){
                cout << a[i] / 2 - (f < 0) << endl;
                if(f < 0) f += 2;
            }
        }
    }
    return 0;
}
