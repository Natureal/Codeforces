#include <bits/stdc++.h>
using namespace std;
 
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
 
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;

int t;
int r, c;
char g[100][100];

int main(){
    cin >> t;
    for(int q = 1; q <= t; ++q){
        cin >> r >> c;
        bool A = false, P = false;
        bool rowA = false;
        bool rowA_top_bottom = false;
        for(int i = 0; i < r; ++i){
            cin >> g[i];
            int numA = 0;
            for(int j = 0; j < c; ++j){
                if(g[i][j] == 'A'){
                    A = true, numA++;
                       
                }
                else P = true;
            }
            if(numA == c){
                rowA = true;
                if(i == 0 || i == r - 1) rowA_top_bottom = true;
            }
        }
        for(int i = 0; i < c; ++i){
            int numA = 0;
            for(int j = 0; j < r; ++j) numA += (g[j][i] == 'A');
            if(numA == r){
                rowA = true;
                if(i == 0 || i == c - 1) rowA_top_bottom = true;
            }
        }
        bool sideA = false;
        if(g[0][0] == 'A' || g[0][c - 1] == 'A' || g[r - 1][0] == 'A' || g[r - 1][c - 1] == 'A')
            sideA = true;
        bool sideOneA = false;
        for(int i = 0; i < r; ++i){
            if(g[i][0] == 'A' || g[i][c - 1] == 'A') sideOneA = true;
        }
        for(int i = 0; i < c; ++i){
            if(g[0][i] == 'A' || g[r - 1][i] == 'A') sideOneA = true;
        }
        if(!P){
            cout << 0 << endl;
        }
        else if(A){
            if(rowA){
                if(rowA_top_bottom) cout << 1 << endl;
                else cout << 2 << endl;
            }
            else if(sideA) cout << 2 << endl;
            else if(sideOneA) cout << 3 << endl;
            else cout << 4 << endl;
        }
        else{
            cout << "MORTAL" << endl;
        }
    }
    
    return 0;
}
