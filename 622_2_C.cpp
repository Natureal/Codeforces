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

int n;
int m[500010];
int R[500010], L[500010];
ll Rres[500010], Lres[500010];
int arr[500010];
stack<pii> st;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    REP(i, 1, n){
        cin >> m[i];
        while(!st.empty()){
            pii tmp = st.top();
            if(tmp.FI < m[i]) break;
            R[tmp.SE] = i;
            st.pop();
        }
        if(!st.empty()) L[i] = st.top().SE;
        st.push(MP(m[i], i));
    }
    ll ans = 0;
    DEC(i, n, 1){
        if(R[i] == 0) Rres[i] = 1LL * (n + 1 - i) * m[i], R[i] = n + 1;
        else{
            Rres[i] = 1LL * (R[i] - i) * m[i] + Rres[R[i]];
        }
    }
    REP(i, 1, n){
        Lres[i] = 1LL * (i - L[i]) * m[i] + Lres[L[i]];
    }
    int pos = 0;
    REP(i, 1, n){
        if(Lres[i] + Rres[i] - m[i] > ans){
            ans = Lres[i] + Rres[i] - m[i];
            pos = i;
        }
    }
    int tpos = pos;
    while(tpos > 0){
        REP(i, L[tpos] + 1, tpos){
            arr[i] = m[tpos];
        }
        tpos = L[tpos];
    }
    tpos = pos;
    while(tpos <= n){
        REP(i, tpos, R[tpos] - 1){
            arr[i] = m[tpos];
        }
        tpos = R[tpos];
    }
    REP(i, 1, n) cout << arr[i] << " ";
    cout << '\n';
    return 0;
}
