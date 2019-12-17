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

int n;
string s;

int check(string tmp, char tar, char ver, bool print){
	int num = 0;
	for(int i = 0; i < tmp.length() - 1; ++i){
		if(tmp[i] != tar){
			tmp[i] = tar;
			num++;
			if(print){
				printf("%d ", i + 1);
			}
			if(tmp[i + 1] != tar){
				tmp[i + 1] = tar;
			}
			else{
				tmp[i + 1] = ver;
			}
		}
	}
	if(tmp[tmp.length() - 1] == tar){
		return num;
	}
	else{
		return -1;
	}
}

int main(){
	cin >> n >> s;
	int ans;
	if((ans = check(s, 'W', 'B', 0)) != -1){
		cout << ans << endl;
		check(s, 'W', 'B', 1);
		cout << endl;
	}
	else if((ans = check(s, 'B', 'W', 0)) != -1){
		cout << ans << endl;
		check(s, 'B', 'W', 1);
		cout << endl;
	}
	else{
		cout << "-1" << endl;
	}
	return 0;
}
