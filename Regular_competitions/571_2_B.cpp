#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): *(s.find_by_order(2), counting from 0)
// order_of_key(k) returns the number of items strictly smaller than item k.
template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, 
        tree_order_statistics_node_update>;

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

char s1[1000010], s2[1000010];
int c1[2] = {0}, c2[2] = {0};

int C(){
    return abs(c1[0] - c2[0]) % 2 == 0;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin >> s1 >> s2;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int ans = 0;
    REP(i, 0, len2 - 1){
        c1[s1[i] - '0']++;
        c2[s2[i] - '0']++;
    }
    ans += C();
    REP(i, len2, len1 - 1){
        c1[s1[i - len2] - '0']--;
        c1[s1[i] - '0']++;
        ans += C();
    }
    cout << ans << endl;
    return 0;
}
