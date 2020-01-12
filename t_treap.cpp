// Do not forget to define maxn
const int maxn = ;
const int INF = (1 << 30) - 1;

struct Treap{
    int root,tcnt;
    int key[maxn], pro[maxn], son[maxn][2], cnt[maxn], sz[maxn];
    void clear(){
        root = 0;
        tcnt = 0;
        pro[0] = INF;
        sz[0] = 0;
    }
    void update(int x){
        sz[x] = cnt[x] + sz[son[x][0]] + sz[son[x][1]];
    }
    void rotate(int &x,int t){
        int y = son[x][t];
        son[x][t] = son[y][1 - t];
        son[y][1 - t] = x;
        update(x);
        update(y);
        x = y;
    }
    void _insert(int &x,int k){
        if(x){ // non-empty subtree
            if(key[x] == k) ++cnt[x];
            else{
                int t = k > key[x];
                _insert(son[x][t],k);
                if(pro[son[x][t]] < pro[x]) rotate(x,t);
            }
        }
        else{ // empty subtree
            x = ++tcnt;
            cnt[x] = 1;
            key[x] = k;
            pro[x] = rand();
        }
        update(x);
    }
    void _erase(int &x,int k){
        if(key[x] == k){
            if(cnt[x] > 1) cnt[x]--;
            else{
                if(!son[x][0] && !son[x][1]){
                    x = 0;
                    return;
                }
                int t = pro[son[x][0]] > pro[son[x][1]];
                rotate(x,t);
                _erase(x,k);
            }
        }
        else _erase(son[x][k > key[x]],k);
    }
    int _get_kth(int &x,int k){
        if(sz[son[x][0]] >= k)
            return _get_kth(son[x][0],k);
        k -= cnt[x] + sz[son[x][0]];
        if(k <= 0) return key[x];
        return _get_kth(son[x][1],k);
    }
    void insert(int k){
        _insert(root,k);
    }
    void erase(int k){
        _erase(root,k);
    }
    int get_kth(int k){
        return _get_kth(root,k);
    }
    int size(){
        return sz[root];
    }
}tp;
