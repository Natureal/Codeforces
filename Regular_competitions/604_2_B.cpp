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

int t;
int L[200010], R[200010];
stack<int> st;

void Proc(int a){
    L[a] = 1;
    int sum = 1;
    while(!st.empty()){
        int tmp = st.top();
        if(tmp < a){
            L[a] += L[tmp];
            R[tmp] = sum;
            sum += L[tmp];
            st.pop();
        }
        else break;
    }
    st.push(a);
}

int main(){
	cin >> t;
    for(int tt = 0; tt < t; ++tt){
        int n;
        cin >> n;
        while(!st.empty()) st.pop();
        for(int j = 1; j <= n; ++j){
            int a;
            cin >> a;
            Proc(a);
        }
        Proc(n + 1);
        for(int i = 1; i <= n; ++i){
            //cout << L[i] << " , " << R[i] << endl;
            if(L[i] + R[i] - 1 == i) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    
    return 0;
}
