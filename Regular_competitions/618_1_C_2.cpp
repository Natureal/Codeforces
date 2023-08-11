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
typedef pair<double,int> pdi;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;
const double eps = 1e-12;

int n;
double a[1000010];
stack<pdi> st;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    REP(i, 1, n){
        if(st.empty()){
            st.push(MP(a[i], 1));
        }
        else{
            pdi cur = MP(a[i], 1);
            while(!st.empty()){
                pdi top = st.top();
                if(top.FI > cur.FI){
                    st.pop();
                    cur.FI = (top.FI * top.SE + cur.FI * cur.SE) / (top.SE + cur.SE);
                    cur.SE += top.SE;
                }
                else break;
            }
            st.push(cur);
        }
    }
    vector<double> V;
    while(!st.empty()){
        pdi top = st.top(); st.pop();
        while(top.SE--) V.PB(top.FI);
    }
    reverse(V.begin(), V.end());
    for(auto v: V) printf("%.12lf\n", v);
    return 0;
}
