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
int num[100010];
int q[100010][3];
set<pii > st[100010];

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n - 2){
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        sort(q[i], q[i] + 3);
        num[q[i][0]]++;
        num[q[i][1]]++;
        num[q[i][2]]++;
        st[q[i][0]].insert(MP(q[i][1], q[i][2]));
        st[q[i][1]].insert(MP(q[i][0], q[i][2]));
        st[q[i][2]].insert(MP(q[i][0], q[i][1]));
    }
    int pos = 0, pre = 0;
    REP(i, 1, n){
        if(num[i] == 1){
            pos = i;
            break;
        }
    }
    bool start = false;
    while(num[pos]){
        pii t = *(st[pos].begin());
        if(num[t.FI] > num[t.SE] || pre == t.SE){
            swap(t.FI, t.SE);
        }
        num[t.FI]--;
        num[t.SE]--;
        st[t.FI].erase(MP(min(pos, t.SE), max(pos, t.SE)));
        st[t.SE].erase(MP(min(pos, t.FI), max(pos, t.FI)));
        if(!start){
            cout << pos << " " << t.FI << " " << t.SE << " ";
            start = true;   
        }
        else{
            cout << t.SE << " ";
        }
        pos = t.FI;
        pre = t.SE;
    }
    cout << endl;
    return 0;
}
