const int maxn = ;

int fail[maxn];

void Get_fail(char *s, int L = -1){
    // fail: length of matched suffix ending from i (index)
    fail[0] = -1;
    int j = -1, len = (L == -1) ? strlen(s) : L;
    REP(i, 1, len - 1){
        while(j >= 0 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        fail[i] = j;
    }
}
