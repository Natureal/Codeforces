const int mod[2] = {1000000007, 1000000009};
const int base[2] = {23, 29};

int HS[2][1000010];

void Pre_HS(int len){
    HS[0][1] = HS[1][1] = 1;
    REP(i, 2, len){
        REP(j, 0, 1) HS[j][i] = (1LL * HS[j][i - 1] * base[j]) % mod[j];
    }
}
