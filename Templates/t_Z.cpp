const int maxn = ;

int Z[maxn], ZX[maxn];

void Get_Z(char *s, int len = -1){
    // Z: the length of the longest matched prefix starting from i (index)
    int L = 0, R = 0;
    len = (len == -1) ? strlen(s + 1) : len;
    Z[1] = len;
    REP(i, 2, len){
        if(i > R){
            L = i, R = i - 1;
            while(R + 1 <= len && s[R - L + 2] == s[R + 1]) R++;
            Z[i] = R - L + 1;
        }
        else{
            int k = 1 + i - L;
            if(Z[k] < R - i + 1) Z[i] = Z[k];
            else{
                L = i;
                while(R + 1 <= len && s[R - L + 2] == s[R + 1]) R++;
                Z[i] = R - L + 1;
            }
        }
    }
}

void Z_match(int *ZX, char *s, char *ref, int len, int ref_len){
    // ZX: the length of the longest substring starting from i which is also a prefix of *ref.
    int L = 0, R = 0;
    REP(i, 1, len){
        if(i > R){
            L = i, R = i - 1;
            while(R + 1 <= len && R - L + 2 <= ref_len && ref[R - L + 2] == s[R + 1]) R++;
            ZX[i] = R - L + 1;
        }
        else{
            int k = 1 + i - L;
            if(Z[k] < R - i + 1) ZX[i] = Z[k];
            else{
                L = i;
                while(R + 1 <= len && R - L + 2 <= ref_len && ref[R - L + 2] == s[R + 1]) R++;
                ZX[i] = R - L + 1;
            }
        }
    }
}
