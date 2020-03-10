const int maxn = ;

int sg[maxn];
bool sghash[maxn];
int K[maxn], kn;

int get_sg(int v){
    MEM(sghash, 0);
    REP(i, 1, kn){
        sghash[sg[v - K[i]]] = true;
    }
    REP(j, 0, 1e9){
        if(!sghash[j]) return j;
    }
    return -1;
}

void cal_sg(){
    MEM(sg, 0);
    REP(i, 1, maxn - 1){
        sg[i] = get_sg(i);
    }
}
