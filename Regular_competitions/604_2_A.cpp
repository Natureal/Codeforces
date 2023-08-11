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
string s;

bool check(string &str){
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == '?'){
            for(int j = 0; j < 3; ++j){
                if(i > 0 && 'a' + j == str[i - 1]) continue;
                if(i + 1 < str.length() && 'a' + j == str[i + 1]) continue;
                str[i] = 'a' + j;
            }
            if(str[i] == '?'){
                return false;
            }
        }
        if(i + 1 < str.length() && str[i] == str[i + 1]) return false;
    }
    return true;
}

int main(){
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> s;
        if(!check(s)){
            cout << -1 << endl;
        }
        else{
            cout << s << endl;
        }
    }
    
    return 0;
}
