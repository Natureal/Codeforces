#pragma GCC optimize("O3")
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
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;

int n, a[100010];
int num[31];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n) cin >> a[i];
    REP(i, 1, n){
        REP(j, 0, 30){
            if(a[i] & (1 << j)) num[j]++;
        }
    }
    int ans = 0, p = 1;
    REP(i, 1, n){
        int tmp[31] = {0}, v = 0;
        REP(j, 0, 30) if(a[i] & (1 << j)){
            if(num[j] == 1) v |= (1 << j);
        }
        if(v > ans){
            ans = v;
            p = i;
        }
    }
    cout << a[p];
    REP(i, 1, n) if(i != p){
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}
