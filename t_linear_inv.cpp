const int maxn = ;

int inv[maxn];

void Cal_inv(){
    inv[1] = 1;
    REP(i, 2, maxn - 1) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
}
