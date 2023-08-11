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

ll f[51], A[51];
int t;

VI Solve_A(int n, ll k){
    if(n == 1){
        VI ans;
        ans.PB(1);
        return ans;
    }
    if(n == 2){
        VI ans;
        ans.PB(2); ans.PB(1);
        return ans;
    }
    printf("Solve %d %lld\n", n, k);
    bool vis[51] = {0};
    VI ans;
    ans.PB(n);
    vis[n] = true;
    REP(i, 2, n){
        REP(j, 1, n - 1){
            if(j == i || (j < i && ans[j - 1] == i))
                continue;
            if(1.0 * k / A[n - i + 1] > n - 2){
                k -= A[n - i + 1] * (n - 2);
            }
            else{
                ans.PB(j);
                break;
            }
        }
    }
    return ans;
}

VI Get(int n, ll k){
    if(n == 1){
        VI ans;
        ans.PB(1);
        return ans;
    }
    printf("Get %d %lld\n", n, k);
    REP(i, 1, n){
        if(1.0 * k / A[i] > f[n - i]){
            k -= A[i] * f[n - i];
        }
        else{
            ll A_order = (k - 1) / f[n - i] + 1;
            ll f_order = (k - 1) % f[n - i] + 1;
            printf("Ao: %lld, fo: %lld\n", A_order, f_order);
            VI ans = Solve_A(i, A_order);
            cout << "ans: ";
            for(auto v: ans) cout << v << " ";
            cout << endl;
            if(i < n){
                cout << "tmp: ";
                VI tmp = Get(n - i, f_order);
                for(auto v: tmp) cout << v << " ";
                cout << endl;
                for(auto v: tmp){
                    ans.PB(v + i);
                }
            }
            return ans;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	f[0] = f[1] = A[1] = 1;
    f[2] = 2;
    A[2] = 1;
    REP(i, 3, 50){
        if(i > 22){
            A[i] = A[i - 1];
            f[i] = f[i - 1];
            continue;
        }
        A[i] = A[i - 1] * (i - 2);
        REP(j, 1, i){
            f[i] += A[j] * f[i - j];
        }
    }
    //REP(i, 1, 50){
      //  printf("f[%d] : %lld, A: %lld\n", i, f[i], A[i]);
    //}
    cin >> t;
    REP(q, 1, t){
        int n;
        ll k;
        cin >> n >> k;
        if(k > f[n]){
            cout << -1 << endl;
            continue;
        }
        VI ans = Get(n, k);
        for(auto v: ans) cout << v << " ";
        cout << endl;
    }
    return 0;
}
