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

int n;

struct Point{
    int x, y, z, id;
}P[50010];

bool cmp(Point a, Point b){
    if(a.z != b.z) return a.z < b.z;
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n;
    REP(i, 1, n){
        cin >> P[i].x >> P[i].y >> P[i].z;
        P[i].id = i;
    }
    sort(P + 1, P + n + 1, cmp);
    //REP(i, 1, n){
      //  printf("--> %d %d %d\n", P[i].x, P[i].y, P[i].z);
    //}
    VI z_rem;
    REP(i, 1, n){
        int j = i;
        while(j + 1 <= n && P[j + 1].z == P[i].z){
            j++;
        }
        VI y_rem;
        REP(k, i, j){
            if(k + 1 <= j && P[k + 1].x == P[k].x){
                 //printf("same x\n");
                 cout << P[k].id << " " << P[k + 1].id << endl;
                 k++;
            }
            else{
                y_rem.PB(k);
            }
        }
        for(int k = 0; k < SZ(y_rem) - 1; ++k){
            cout << P[y_rem[k]].id << " " << P[y_rem[k + 1]].id << endl;
            k++;
        }
        if(SZ(y_rem) % 2) z_rem.PB(y_rem[SZ(y_rem) - 1]);
        //printf("inter: %d %d, szz: %d\n", i, j, SZ(z_rem));
        i = j;
    }
    for(int i = 0; i < SZ(z_rem) - 1; ++i){
        cout << P[z_rem[i]].id << " " << P[z_rem[i + 1]].id << endl;
        i++;
    }
    return 0;
}
