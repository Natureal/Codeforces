// Remember to define the range of fa[].
const int maxn = ;
int fa[maxn];

int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x != y){
        fa[x] = y;
    }
}
