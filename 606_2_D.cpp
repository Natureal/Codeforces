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
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 3;

int t, n;
map<pii, int> mp;
vector<int> v01, v10;
int avai[200010];

pii get_hash(string s){
	int v1 = 0, b1 = 1, v2 = 0, b2 = 1;
	for(int i = 0; i < s.length(); ++i){
		b1 = (1LL * b1 * 137) % mod1;
		b1 = (1LL * b2 * 137) % mod2;
		v1 = (1LL * v1 * b1 + s[i]) % mod1;
		v2 = (1LL * v2 * b2 + s[i]) % mod2;
	}
	return MP(v1, v2);
}

int main(){
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> n;
		int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
		v01.clear();
		v10.clear();
		memset(avai, 0, sizeof(avai));
		mp.clear();
		for(int j = 1; j <= n; ++j){
			string tmp;
			cin >> tmp;
			pii hs_tmp = get_hash(tmp);
			mp[hs_tmp] = j;
			if(tmp[0] != tmp[tmp.length() - 1]){
				if(tmp[0] == '0') avai[j] = 1;
				else avai[j] = 2;
				reverse(tmp.begin(), tmp.end());
				pii hs_tmp_reverse = get_hash(tmp);
				if(mp[hs_tmp_reverse]){
					avai[mp[hs_tmp_reverse]] = -1;
					avai[j] = -1;
				}
			}
			reverse(tmp.begin(), tmp.end());
			if(tmp[0] == '0'){
				if(tmp[tmp.length() - 1] == '0') c00++;
				else{
					c01++;
				}
			}
			else{
				if(tmp[tmp.length() - 1] == '0'){
					c10++;
				}
				else c11++;
			}
		}
		for(int j = 1; j <= n; ++j) if(avai[j] > 0){
			if(avai[j] == 1) v01.PB(j);
			else v10.PB(j);
		}
		if(c01 == 0 && c10 == 0){
			if(c00 > 0 && c11 > 0) printf("-1\n");
			else printf("0\n\n");
		}
		else{
			if(c01 == c10) printf("0\n\n");
			else{
				int dif = abs(c01 - c10);
					dif /= 2;
					printf("%d\n", dif);
					if(c01 > c10){
						for(int k = 0; k < dif; ++k) printf("%d ", v01[k]);
					}
					else{
						for(int k = 0; k < dif; ++k) printf("%d ", v10[k]);
					}
					printf("\n");
			}
		}
	}
	return 0;
}
