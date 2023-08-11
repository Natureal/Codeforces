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

int n, m, k;
vector<pair<int, string> > ans;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
    int sum = 4 * n * m - 2 * n - 2 * m;
    if(k > sum){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, 1, n){
        if(i < n && m > 1){
        if(k >= (m - 1) * 3){
            k -= (m - 1) * 3;
            ans.PB(MP(m - 1, string("RDU")));
        }
        else{
            int cur = 0;
            while(k--){
                if(cur == 0) cur = 1, ans.PB(MP(1, "R"));
                else if(cur == 1) cur = 2, ans.PB(MP(1, "D"));
                else cur = 0, ans.PB(MP(1, "U"));
            }
            break;
        }
        }
        else if(m > 1){
            if(k >= (m - 1)){
                k -= (m - 1);
                ans.PB(MP(m - 1, string("R")));
            }
            else{
                while(k--){
                    ans.PB(MP(1, "R"));
                }
                break;
            }
        }
        //=====
        if(k >= (m - 1) && m > 1){
            k -= (m - 1);
            ans.PB(MP(m - 1, string("L")));
        }
        else if(m > 1){
            while(k--){
                ans.PB(MP(1, "L"));
            }
            break;
        }
        if(k == 0) break;
        // =====
        if(i < n && n > 1){
            k--;
            ans.PB(MP(1, string("D")));
        }
        else if(n > 1){
            while(k--){
                ans.PB(MP(1, string("U")));
            }
        }
    }
    cout << SZ(ans) << endl;
    for(auto v: ans){
        cout << v.FI << " " << v.SE << endl;
    }
    return 0;
}
