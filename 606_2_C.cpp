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
char s[200010];

int main(){
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> s;
		int len = strlen(s);
		vector<int> ans;
		for(int j = 0; j < len; ++j){
			if((s[j] == 't' || s[j] == 'o') && j < len - 2){
				if(s[j] == 't' && s[j + 1] == 'w' && s[j + 2] == 'o'){
					if(j < len - 3 && s[j + 3] == 'o'){
						s[j + 1] = 'a';
						ans.PB(j + 1);
					}
					else{
						s[j + 2] = 'b';
						ans.PB(j + 2);
					}
				}
				else if(s[j] == 'o' && s[j + 1] == 'n' && s[j + 2] == 'e'){
					s[j + 1] = 'c';
					ans.PB(j + 1);
				}
			}
		}
		printf("%d\n", ans.size());
		for(int j = 0; j < ans.size(); ++j) printf("%d ", ans[j] + 1);
		printf("\n");
	}
	return 0;
}
