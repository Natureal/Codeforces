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

int n, l, r;
char s[300010];
int v[300010], tv[300010], c1[300010], c2[300010];
queue<pii > Q1, Q2;

int Lowbit(int x){
    return x & (-x);
}

void Update(int x, int c[], int d){
    while(x <= n){
        c[x] += d;
        x += Lowbit(x);
    }
}

int Getsum(int x, int c[]){
    int res = 0;
    while(x){
        res += c[x];
        x -= Lowbit(x);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> s + 1;
    int tmin = 1e9;
    int n_tmin = 0;
    REP(i, 1, n){
        v[i] = v[i - 1];
        if(s[i] == '(') v[i]++;
        else v[i]--;
        tmin = min(tmin, v[i]);
    }
    if(v[n] != 0){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    REP(i, 1, n){
        n_tmin += (v[i] == tmin);
    }
    int ans = n_tmin, ans_l = 1, ans_r = 1;
    int pre_right = 0;
    REP(i, 1, n){
        if(s[i] == ')') pre_right = i;
        if(v[i] <= tmin + 1) Q1.push(MP(i, pre_right));
        if(v[i] == tmin) Q2.push(MP(i, pre_right));
        if(v[i] == tmin + 2) Update(i, c1, 1);
        if(v[i] == tmin + 1) Update(i, c2, 1);
    }
    // tmin + 2, res: tmin + 1
    int first_left = n, last_right = 1, n_tmin_1 = 0;
    REP(i, 1, n){
        if(s[i] == ')') first_left = i;
        if(v[i] == tmin) break;
        n_tmin_1 += (v[i] == tmin + 1);
    }
    DEC(i, n, 1){
        if(v[i] == tmin) break;
        if(s[i] == '(') last_right = i;
        n_tmin_1 += (v[i] == tmin + 1);
    }
    if(first_left < last_right && n_tmin_1 > ans){
        ans = n_tmin_1;
        ans_l = first_left;
        ans_r = last_right;
    }
    // tmin + 2, res: tmin + 2
    first_left = n, last_right = 1;
    int n_tmin_2 = 0;
    REP(i, 1, n){
        if(s[i] == ')') first_left = i;
        if(v[i] <= tmin + 1) break;
        n_tmin_2 += (v[i] == tmin + 2);
    }
    DEC(i, n, 1){
        if(v[i] <= tmin + 1) break;
        if(s[i] == '(') last_right = i;
        n_tmin_2 += (v[i] == tmin + 2);
    }
    if(first_left < last_right){
        int num = 0;
        REP(i, first_left, last_right - 1) num += (v[i] == tmin);
        if(num + n_tmin_2 > ans){
            ans = num + n_tmin_2;
            ans_l = first_left;
            ans_r = last_right;
        }
    }
    // tmin+2 - 2/ tmin+1 - 2
    REP(i, 1, n - 1){
        if(s[i] == '('){
            while(!Q1.empty() && Q1.front().FI < i) Q1.pop();
            while(!Q2.empty() && Q2.front().FI < i) Q2.pop();
            int right = pre_right;
            if(!Q1.empty()) right = Q1.front().SE;
            if(right > i){
                int res = Getsum(right - 1, c1) - Getsum(i - 1, c1);
                if(res + n_tmin > ans){
                    ans = res + n_tmin;
                    ans_l = i;
                    ans_r = right;
                }    
            }
            right = pre_right;
            if(!Q2.empty()) right = Q2.front().SE;
            if(right > i){
                int res = Getsum(right - 1, c2) - Getsum(i - 1, c2);
                if(res > ans){
                    ans = res;
                    ans_l = i;
                    ans_r = right;
                }
            }
        }
    }
    cout << ans << endl;
    cout << ans_l << " " << ans_r << endl;
    return 0;
}
