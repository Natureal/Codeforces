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
 
int n, k, m;
set<int> st;
 
pii Query(int avoid = 0){
    cout << "?";
    for(auto v: st) if(v != avoid){
        cout << " " << v;
    }
    cout << endl;
    cout.flush();
    pii ans;
    cin >> ans.FI >> ans.SE;
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
    if(k == 1){
        cout << "! " << 1 << endl;
        return 0;  
    }
    REP(i, 1, k) st.insert(i);
    pii ans1 = Query();
    st.erase(ans1.FI);
    st.insert(k + 1);
    pii ans2 = Query();
    st.erase(ans2.FI);
    //
    int n_big = 0, n_small = 0;
    st.insert(ans1.FI);
    st.insert(ans2.FI);
    int a = 0;
    for(auto v: st){
        if(v != ans1.FI && v != ans2.FI){
            pii t_ans = Query(v);
            if(ans1.SE > ans2.SE){
                if(t_ans.SE > ans2.SE) n_small++;
            }
            else{
                if(t_ans.SE == ans2.SE) n_small++;
            }
        }
    }
    cout << "! " << n_small + 1 << endl;
    return 0;
}
