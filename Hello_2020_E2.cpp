// Geometry, Polar sort (long long)
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
typedef vector<int> VI;
const int mod = 1000000007;

int n;

struct Point{
    ll x, y;
    Point(ll a = 0, ll b = 0): x(a), y(b) {}
    bool operator < (const Point &b) const{
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
}P[2510], OP[2510];

// Direction: counterclockwise = positive
ll Cross(Point st, Point a, Point b){
    Point A(a.x - st.x, a.y - st.y);
    Point B(b.x - st.x, b.y - st.y);
    return A.x * B.y - A.y * B.x;
}

bool cmp(Point a, Point b){
    Point st = P[1];
    Point A(a.x - st.x, a.y - st.y);
    Point B(b.x - st.x, b.y - st.y);
    bool bh1 = A < Point(0, 0), bh2 = B < Point(0, 0);
    if(bh1 != bh2) return bh1 < bh2;
    return Cross(st, a, b) > 0;
}

int C2(int k){
    if(k <= 0) return 0;
    return k * (k - 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> OP[i].x >> OP[i].y;
    }
    ll ans = 0;
    REP(i, 1, n){
        REP(j, 1, n) P[j] = OP[j];
        // for point i
        swap(P[1], P[i]);
        sort(P + 2, P + n + 1, cmp);
        int pos = 2, n_pos = 0;
        ll cnt = 0;
        REP(j, 2, n){
            if(n_pos == 0) pos = j;
            else n_pos--;
            int nxt_pos = (pos + 1 > n) ? 2 : pos + 1;
            while(nxt_pos != j && Cross(P[1], P[j], P[nxt_pos]) > 0){
                pos = nxt_pos;
                n_pos++;
                nxt_pos = (pos + 1 > n) ? 2 : pos + 1;
            }
            cnt += C2(n_pos) + C2(n - 2 - n_pos);
        }
        ans += 1LL * (n - 4) * (1LL * (n - 1) * (n - 2) * (n - 3) / 6 - cnt / 2);
    }
    cout << ans / 2 << endl;
    return 0;
}
