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

const int mod[2] = {1000000007, 1000000009};
const int base[2] = {23, 29};

int HS[2][100010];

void Pre_HS(int len){
    HS[0][1] = HS[1][1] = 1;
    REP(i, 2, len){
        REP(j, 0, 1) HS[j][i] = (1LL * HS[j][i - 1] * base[j]) % mod[j];
    }
}

int n;
pii ED[2][100010], ST[2][100010];
int hash_record1[2][100010], hash_record2[2][100010];

void Solve(int a, int b, int hash_record[2][100010]){
    int pre = 0, cur_hash[2] = {0};
    REP(i, 1, n){
        int cur_id = ST[a][i].SE;
        while(pre + 1 <= n && ED[a][pre + 1].FI < ST[a][i].FI){
            int id = ED[a][pre + 1].SE;
            REP(j, 0, 1) cur_hash[j] = (cur_hash[j] + HS[j][id]) % mod[j];
            pre++;
        }
        REP(j, 0, 1) hash_record[j][cur_id] = cur_hash[j];
    }
    int suf = n + 1;
    MEM(cur_hash, 0);
    DEC(i, n, 1){
        int cur_id = ED[a][i].SE;
        while(suf - 1 >= 1 && ST[a][suf - 1].FI > ED[a][i].FI){
            int id = ST[a][suf - 1].SE;
            REP(j, 0, 1) cur_hash[j] = (cur_hash[j] + HS[j][id]) % mod[j];
            suf--;
        }
        REP(j, 0, 1) hash_record[j][cur_id] = (hash_record[j][cur_id] + cur_hash[j]) % mod[j];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    Pre_HS(n);
    REP(i, 1, n){
        int sa, ea, sb, eb;
        cin >> sa >> ea >> sb >> eb;
        ST[0][i] = MP(sa, i), ED[0][i] = MP(ea, i);
        ST[1][i] = MP(sb, i), ED[1][i] = MP(eb, i);
    }
    REP(i, 0, 1) sort(ST[i] + 1, ST[i] + n + 1), sort(ED[i] + 1, ED[i] + n + 1);
    Solve(0, 1, hash_record1);
    Solve(1, 0, hash_record2);
    bool f = true;
    REP(i, 1, n){
        REP(j, 0, 1) if(hash_record1[j][i] != hash_record2[j][i]) f = false;
        if(!f) break;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
