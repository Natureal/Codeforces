int Lowbit(int x){
    return x & (-x);
}

void Update(int x, int d){
    while(x <= n){
        c[x] += d;
        x += Lowbit(x);
    }
}

int Getsum(int x){
    int res = 0;
    while(x){
        res += c[x];
        x -= Lowbit(x);
    }
    return res;
}
