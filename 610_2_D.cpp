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
const int mod = 1000000007;

int send_recv(string &tmp){
    cout << tmp << endl;
    //cout.flush();
    int v;
    cin >> v;
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    string a300 = "", b300 = "";
    REP(i, 1, 300){
        a300 += 'a';
        b300 += 'b';
    }
    int na = 300 - send_recv(a300), nb = 300 - send_recv(b300);
    if(na == 0 || nb == 0){
        string s = "";
        char plus = (na == 0) ? 'b' : 'a';
        s += plus;
        while(send_recv(s)){
            s += plus;
        }
        return 0;
    }
    string all_a = "", s = "";
    REP(i, 1, na + nb) all_a += 'a';
    s = all_a;
    int ka = 0, kb = 0;
    REP(i, 1, na + nb){
        if(ka == na){
            s[i - 1] = 'b';
            kb++;
            continue;
        }
        string ts = all_a;
        ts[i - 1] = 'b';
        int v = send_recv(ts);
        if(v < nb){
            s[i - 1] = 'b';
            kb++;
        }
        else{
            ka++;
        }
        if(kb == nb) break;
    }
    send_recv(s);
    return 0;
}
