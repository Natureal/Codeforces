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
const int mod = 1000000007;

int n, p;
int t[100010];
ll ans[100010];

struct event{
    ll time;
    int type, index;
    event(ll t, int type, int id): time(t), type(type), index(id) {}
};

struct cmp{
    bool operator ()(event a, event b){
        if(a.time == b.time){
            if(a.type == b.type){
                return a.index > b.index;
            }
            return a.type > b.type;
        }
        return a.time > b.time;
    }
};

priority_queue<event, vector<event> , cmp> PQ;
priority_queue<int, vector<int>, greater<int> > Wait;
queue<int> Q;
set<int> Q_min;

int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> p;
    REP(i, 1, n){
        cin >> t[i];
        PQ.push(event(t[i], 1, i));
    }
    ll cur_time = 0;
    while(!PQ.empty()){
        event cur_event = PQ.top(); PQ.pop();
        //printf("e: %lld %d %d\n", cur_event.time, cur_event.type, cur_event.index);
        if(cur_event.type == 0){
            // finish
            Q_min.erase(Q.front());
            Q.pop();
            cur_time = cur_event.time;
            ans[cur_event.index] = cur_time;
            if(!Q.empty()){
                PQ.push(event(cur_time + p, 0, Q.front()));
                //printf("out next Q\n");
            }
            else if(!Wait.empty()){
                PQ.push(event(cur_time, 1, Wait.top()));
                Wait.pop();
               // printf("out next W\n");
            }
        }
        else{
            if(Q.empty() || cur_event.index < *(Q_min.begin())){
                if(Q.empty()){
                    PQ.push(event(cur_event.time + p, 0, cur_event.index));
                }
                Q.push(cur_event.index);
                Q_min.insert(cur_event.index);
                //printf("en Queue\n");
            }
            else{
                Wait.push(cur_event.index);
               // printf("en Wait\n");
            }
        }
    }
    REP(i, 1, n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
