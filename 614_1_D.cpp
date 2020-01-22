#pragma GCC optimize("O3")
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
typedef vector<pii > VPI;
typedef vector<pll > VPL;
const int mod = 1000000007;

map<int, int> Cnt;
map<pii, int> ID;
VPI PF[5010];
int n, num[5010], id_tot;
int C[5010 * 1010];
VI Point[5010];

int Make(int a, int b){
    int sum = 0;
    REP(i, 0, min(SZ(PF[a]), SZ(PF[b])) - 1){
        if(PF[a][i].FI != PF[b][i].FI) break;
        sum += min(PF[a][i].SE, PF[b][i].SE);
        if(PF[a][i].SE != PF[b][i].SE) break;
    }
    if(sum == 0) return 0;
    if(ID[MP(a, sum)] == 0){
        if(ID[MP(b, sum)] == 0) ID[MP(a, sum)] = ID[MP(b, sum)] = ++id_tot;
        else ID[MP(a, sum)] = ID[MP(b, sum)];
    }
    else ID[MP(b, sum)] = ID[MP(a, sum)];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, 1, n){
        int a;
        cin >> a;
        if(a == 0) a = 1;
        num[a]++;
    }
    REP(i, 1, 5000){
        int ti = i;
        for(int j = 2; j * j <= i; ++j){
            while(ti % j == 0){
                ti /= j;
                Cnt[j]++;
            }
        }
        if(ti > 1) Cnt[ti]++;
        for(auto v: Cnt) PF[i].PB(v);
        reverse(PF[i].begin(), PF[i].end());
    }
    ID[MP(1, 0)] = ++id_tot;
    ll ans = 0, tsum = 0;
    REP(i, 2, 5000){
        ID[MP(i, 0)] = 1;
        set<int> V;
        REP(j, 2, 5000){
            int res = Make(i, j);
            V.insert(res);
        }
        for(auto v: V){
            int id = ID[MP(i, v)];
            C[id] += num[i];
            Point[i].PB(v);
        }
        tsum += 1LL * num[i] * Point[i].back();
    }
    ans = tsum;
    REP(i, 2, 5000) if(num[i]){
        ll res = tsum;
        int pre = 0;
        REP(j, 0, SZ(Point[i]) - 1){
            int v = Point[i][j], id = ID[MP(i, v)];
            if(n - 2 * C[id] < 0){
                res = res + 1LL * (v - pre) * (n - 2 * C[id]);
                pre = v;
            }
            else break;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
