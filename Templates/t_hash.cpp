// Define maxn. Base-B number system.
const int maxn = ;

struct Hash{
    // hash is 1-based index, but the input and output are 0-based index
    int base[2][maxn], hs[2][maxn], len;
    int B[2] = {239, 229}, mod[2] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9};
    void init(char *s, int L = -1){
        len = (L == -1) ? strlen(s) : L;
        base[0][0] = base[1][0] = 1;
        hs[0][0] = hs[1][0] = 0;
        REP(i, 1, len) REP(j, 0, 1){
            base[j][i] = 1LL * base[j][i - 1] * B[j] % mod[j];
            hs[j][i] = (1LL * hs[j][i - 1] * B[j] % mod[j] + s[i - 1]) % mod[j];
        }
    }
    pii get(int l, int r){ // 0-based index
        int res[2];
        REP(i, 0, 1)
            res[i] = ((hs[i][r + 1] - 1LL * hs[i][l] * base[i][r - l + 1] % mod[i])
                        % mod[i] + mod[i]) % mod[i];
        return MP(res[0], res[1]);
    }
}HS;
