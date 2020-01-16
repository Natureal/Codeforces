const int maxn = ;
int fail[maxn];

void Get_fail(char *s, int L = -1){
    // fail: length of matched suffix ending with i (index)
    fail[0] = -1;
    int j = -1, len = (L == -1) ? strlen(s) : L;
    REP(i, 1, len - 1){
        while(j >= 0 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        fail[i] = j;
    }
}

// to be checked
void KMP(char *s1, char *s2, int L1 = -1, int L2 = -1){
    int len1 = (L1 == -1) ? strlen(s1) : L1;
    int len2 = (L2 == -1) ? strlen(s2) : L2;
    int j = -1;
    REP(i, 0, len1 - 1){
        while(j >= 0 && s2[j + 1] != s1[i]) j = fail[j];
        if(s2[j + 1] == s1[i]) j++;
        // if match
        if(j == len2 - 1){
            j = fail[j];
            // do something
        }
    }
}
