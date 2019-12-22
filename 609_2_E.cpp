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

int n, a[200010], p[200010], c[200010];
ll inv[200010];
set<int> st;
set<int>::iterator it;

int Lowbit(int x){
    return x & (-x);
}

void Update(int x, int d){
    while(x <= n){
        c[x] += d;
        x += Lowbit(x);
    }
}

int Getsum(int x){
    int res = 0;
    while(x){
        res += c[x];
        x -= Lowbit(x);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> a[i];
        p[a[i]] = i;
    }
    // init
    cout << "0 ";
    int center = p[1], lnum = 0, rnum = 0;
    ll sum = 0;
    st.insert(p[1]);
    Update(p[1], 1);
    // end init
    REP(i, 2, n){
        inv[i] = Getsum(n) - Getsum(p[i]);
        Update(p[i], 1);
        st.insert(p[i]);
        ll nxt_sum = sum + inv[i] + abs(p[i] - center) - abs(Getsum(center) - Getsum(p[i]));
        //printf("i %d, %lld\n", i, nxt_sum);
        if(center < p[i])
            nxt_sum -= inv[i];
        else
            nxt_sum -= Getsum(p[i] - 1);
        // check moving center
        if(p[i] > center) rnum++;
        else lnum++;
        if(lnum == rnum + 1){
            // move left
            it = st.find(center);
            it--;
            center = (*it);
            lnum--;
            rnum++;
        }
        if(rnum == lnum + 2){
            // move right
            it = st.find(center);
            it++;
            nxt_sum -= ((*it) - center - 1);
            center = (*it);
            lnum++;
            rnum--;
        }
        sum = nxt_sum;
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
