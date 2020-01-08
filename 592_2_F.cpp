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
const int mod = 1000000007;

int n, k;
int bs[200010];
char s[200010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> k >> s;
    REP(i, 0, n - 1){
        int last = (i - 1 < 0) ? n - 1 : i - 1;
        int nxt = (i + 1 >= n) ? 0 : i + 1;
        if(s[i] == s[last] || s[i] == s[nxt]) bs[i] = 1;
    }
    queue<int> Q[2];
    int id = 0;
    REP(i, 0, n - 1) if(!bs[i]){
        int last = (i - 1 < 0) ? n - 1 : i - 1;
        int nxt = (i + 1 >= n) ? 0 : i + 1;
        if(bs[last] || bs[nxt]) Q[id].push(i);
    }
    int time = k;
    while(!Q[id].empty() && time--){
        VI to_be_bs;
        while(!Q[id].empty()){
            int i = Q[id].front(); Q[id].pop();
            if(bs[i]) continue;
            int last = (i - 1 < 0) ? n - 1 : i - 1;
            int nxt = (i + 1 >= n) ? 0 : i + 1;
            if(bs[last]){
                s[i] = s[last];
                to_be_bs.PB(i);
                if(!bs[nxt]) Q[id ^ 1].push(nxt);
            }
            else if(bs[nxt]){
                s[i] = s[nxt];
                to_be_bs.PB(i);
                if(!bs[last]) Q[id ^ 1].push(last);
            }
        }
        for(auto v: to_be_bs) bs[v] = 1;
        id ^= 1;
    }
    REP(i, 0, n - 1) if(!bs[i] && (k & 1)){
        if(s[i] == 'B') s[i] = 'W';
        else s[i] = 'B';
    }
    cout << s << endl;
    return 0;
}
