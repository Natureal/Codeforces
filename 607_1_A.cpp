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
const int mod = 1e9 + 7;

int t;

int main(){
	cin >> t;
    for(int q = 1; q <= t; ++q){
        int x;
        cin >> x;
        string s;
        cin >> s;
        int L = s.length();
        int l = 0;
        while(s.length() < x){
            l++;
            int v = s[l - 1] - '0';
            if(v > 1){
                string tmp = "";
                for(int i = l; i < s.length(); ++i) tmp += s[i];
                for(int i = 0; i < v - 1; ++i) s += tmp;
            }
        }
        l = 0;
        while(l < x){
            l++;
            int v = s[l - 1] - '0';
            L = (l + 1LL * ((L - l) % mod + mod) * v % mod) % mod;
        }
        cout << L << endl;
    }
    
    return 0;
}
