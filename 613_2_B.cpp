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

int t, n;
int A[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n;
        ll sum = 0;
        REP(i, 1, n){
            cin >> A[i];
            sum += A[i];
        }
        bool exit = false;
        ll pre = A[1], tmin = A[1];
        if(pre >= sum) exit = true;
        REP(i, 2, n){
            pre += A[i];
            if(pre - tmin >= sum) exit = true;
            if(i < n && pre >= sum) exit = true;
            tmin = min(tmin, pre);
        }
        cout << (exit ? "NO" : "YES") << endl;
    }
    return 0;
}
