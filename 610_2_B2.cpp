// binary search
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

int t, n, p, k;
int a[200010];

bool check(int m){
    int v = m;
    ll cost = 0;
    while(m >= k){
        cost += a[m];
        m -= k;
    }
    while(m){
        cost += a[m];
        m--;
    }
    //printf("%d : %lld\n", v, cost);
    return cost <= p;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> t;
    REP(q, 1, t){
        cin >> n >> p >> k;
        REP(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        int l = 0, r = n / k;
        while(l < r){
            int mid = getmid(l, r);
            if(check(mid * k)) l = mid + 1;
            else r = mid;
        }
        l *= k;
        if(l > n || check(l) == false) l -= k;
        r = min(n, l + k - 1);
        while(l < r){
            int mid = getmid(l, r);
            if(check(mid)) l = mid + 1;
            else r = mid;
        }
        if(l > n || check(l) == false) l--;
        cout << l << endl;
    }
    return 0;
}
