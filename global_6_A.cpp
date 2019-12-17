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

int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        bool all_zero = true;
        int zero = 0;
        int even = 0, sum = 0;
        for(int j = 0; j < s.length(); ++j){
            if(s[j] != '0'){
                all_zero = false; 
                sum += s[j] - '0';
                if((s[j] - '0') % 2 == 0){
                    even++;
                }
            }
            else zero++;
        }
        if(all_zero){
            cout << "red" << endl;
        }
        else{
            if(zero >= 1 && (even | zero > 1) && sum % 3 == 0) cout << "red" << endl;
            else cout << "cyan" << endl;
        }
    }
    
    return 0;
}
