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

int n, m, s[5010], f[5010], h[5010];
int L[5010], R[5010], sta[5010][3], tsta[5010][3], vis[5010], inv[2500 * 2500 + 2];
VI GL[5010];

pii Cal(int l, int r, int b){
    if(b == 0){
        int num = (l > 0) + (r > 0);
        int way = 1LL * max(l, 1) * max(r, 1) % mod;
        return MP(num, way);
    }
    else{
        if(l == 0 && r == 0){
            if(b == 1) return MP(1, 2);
            else return MP(2, 1LL * b * (b - 1) % mod);
        }
        else if(l == 0){
            return MP(2, 1LL * b * (r + b - 1) % mod);
        }
        else if(r == 0){
            return MP(2, 1LL * b * (l + b - 1) % mod);
        }
        else{
            int num = 2;
            int way = (((1LL * l * r % mod + 1LL * b * r % mod) % mod
                        + 1LL * l * b % mod) % mod + 1LL * b * (b - 1) % mod) % mod;
            return MP(num, way);
        }
    }
}

void Update(int &a, int &b, int a1, int b1){
    if(a1 > a){
        a = a1;
        b = b1;
    }
    else if(a1 == a){
        b = (b + b1) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    inv[1] = 1;
    REP(i, 2, 2500 * 2500) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    scanf("%d %d", &n, &m);
    REP(i, 1, n){
        scanf("%d", &s[i]);
        GL[s[i]].PB(i);
    }
    REP(i, 1, m){
        scanf("%d %d", &f[i], &h[i]);
        if(SZ(GL[f[i]]) >= h[i]){
            L[GL[f[i]][h[i] - 1]] = i;
            R[GL[f[i]][SZ(GL[f[i]]) - h[i]]] = i;
        }
    }
    int pren = 0, prew = 1;
    int ans = 0, answ = 1;
    REP(i, 1, n) if(L[i]){
        int id = L[i], cur = f[id];
        pii tmp = Cal(sta[cur][0], sta[cur][1], sta[cur][2]);
        pren -= tmp.FI;
        prew = 1LL * prew * inv[tmp.SE] % mod;
        sta[cur][0]++;
        tmp = Cal(sta[cur][0], sta[cur][1], sta[cur][2]);
        pren += tmp.FI;
        //printf("i: %d, pre: %d %d\n", i, pren, prew);
        Update(ans, answ, pren, 2LL * prew % mod);
        int tpren = pren, tprew = prew, mem = tmp.SE;
        memcpy(tsta, sta, sizeof(sta));
        DEC(j, n, i + 1) if(R[j] && R[j] != L[i]){
            int rid = R[j], rcur = f[rid];
            if(rcur == cur){
                tmp.FI = 1 + (tsta[rcur][1] > 0 || tsta[rcur][2] > 0);
                tmp.SE = max(1, tsta[rcur][1] + tsta[rcur][2]);
                pren -= tmp.FI;
                prew = 1LL * prew * inv[tmp.SE] % mod;
                if(vis[rid]) tsta[rcur][0]--, tsta[rcur][2]++;
                else tsta[rcur][1]++;
                tmp.FI = 1 + (tsta[rcur][1] > 0 || tsta[rcur][2] > 0);
                tmp.SE = max(1, tsta[rcur][1] + tsta[rcur][2]);
                pren += tmp.FI;
                Update(ans, answ, pren, prew);
                prew = 1LL * prew * tmp.SE % mod;
            }
            else{
                tmp = Cal(tsta[rcur][0], tsta[rcur][1], tsta[rcur][2]);
                pren -= tmp.FI;
                prew = 1LL * prew * inv[tmp.SE] % mod;
                if(vis[rid]) tsta[rcur][0]--, tsta[rcur][2]++;
                else tsta[rcur][1]++;
                Update(ans, answ, pren + 1 + (tsta[rcur][0] > 0 || (tsta[rcur][2] - vis[rid])
                            > 0),
                        1LL * prew * max(1, tsta[rcur][0] + tsta[rcur][2] - vis[rid]) % mod);
                tmp = Cal(tsta[rcur][0], tsta[rcur][1], tsta[rcur][2]);
                pren += tmp.FI;
                prew = 1LL * prew * tmp.SE % mod;
            }
        }
        pren = tpren, prew = tprew;
        prew = 1LL * prew * mem % mod;
        vis[id] = 1;
    }
    printf("%d %d\n", ans, answ);
    return 0;
}
