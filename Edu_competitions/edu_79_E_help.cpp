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

int b[1000];
int vis[1000], vc;
int n;
vector<vector<int> > G;
vector<int> tmp;
int ct;

void Dfs(int p){
    vis[p] = vc;
    if(!vis[b[p]]) Dfs(b[p]);
}

bool cmp(vector<int> A, vector<int> B){
    return A[0] < B[0];
}

void run(){
    //REP(i, 1, n){
      //  cout << b[i] << " ";
    //}
    MEM(vis, 0);
    for(auto &v: G){
        v.clear();
    }
    G.clear();
    vc = 0;
    REP(i, 1, n) if(vis[b[i]] == 0){
        vc++;
        tmp.clear();
        Dfs(b[i]);
        REP(j, 1, n) if(vis[b[j]] == vc){
            tmp.PB(b[j]);
        }
        int pos = 0;
        REP(j, 0, SZ(tmp) - 1){
            if(tmp[j] > tmp[pos]){
                pos = j;
            }
        }
        vector<int> t;
        REP(j, pos, SZ(tmp) - 1){
            t.PB(tmp[j]);
        }
        REP(j, 0, pos - 1){
            t.PB(tmp[j]);
        }
        G.PB(t);
    }
    sort(G.begin(), G.end(), cmp);
    bool f = true;
    int tot = 0;
    for(auto v: G){
        for(auto o: v){
            if(o != b[++tot]){
                f = false;
                break;
            }
        }
        if(!f) break;
    }
    if(f){
    for(auto v: G){
        for(auto o: v){
            cout << o << " ";
        }
        cout << ", ";
    }
        cout << "good " << ++ct << endl;
    }
    else{
        //cout << "bad" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	int a[1000];
    cin >> n;
    REP(i, 1, n) a[i] = i;
    do{
        REP(i, 1, n) b[i] = a[i];
        run();
    }while(next_permutation(a + 1, a + n + 1));
    cout << "num: " << ct << endl;
    return 0;
}
