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

int t, n, a, b, c;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        int sum = a + b + c;
        int top = a + b + c;
        string s2;
        REP(i, 0, top - 1){
            if(s[i] == 'R' && b){
                s2 += 'P';
                b--;
            }
            else if(s[i] == 'P' && c){
                s2 += 'S';
                c--;
            }
            else if(s[i] == 'S' && a){
                s2 += 'R';
                a--;
            }
            else{
                s2 += 'K';
            }
        }
        REP(i, 0, top - 1){
            if(s2[i] == 'K'){
                sum--;
                if(a){
                    s2[i] = 'R';
                    a--;
                }
                else if(b){
                    s2[i] = 'P';
                    b--;
                }
                else if(c){
                    s2[i] = 'S';
                    c--;
                }
            }
        }
        if(sum >= (n + 1) / 2){
            cout << "YES" << endl;
            cout << s2 << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
