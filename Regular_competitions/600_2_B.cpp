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

int n;
int a[100010];
map<int, int> mp;
set<int> st;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    int pre = 0;
    VI V;
    REP(i, 1, n) cin >> a[i];
    bool f = true;
    REP(i, 1, n){
        if(a[i] > 0){
            if(st.find(a[i]) == st.end() && mp[a[i]] == 0){
                st.insert(a[i]);
            }
            else{
                f = false;
                break;
            }
        }
        else{
            if(st.find(-a[i]) != st.end() && mp[a[i]] == 0){
                st.erase(-a[i]);
                mp[a[i]] = 1;
            }
            else{
                f = false;
                break;
            }
        }
        if(i == n && !st.empty()){
            f = false;
            break;
        }
        if(st.empty()){
            V.PB(i - pre);
            mp.clear();
            pre = i;
        }
    }
    if(!f){
        cout << -1 << endl;
        return 0;
    }
    cout << SZ(V) << endl;
    for(auto v: V){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
