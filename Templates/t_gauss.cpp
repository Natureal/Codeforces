// Remember to define the top, number of column.
int top = ;

bool Gauss(){
    int i,col;
    for(i = 0,col = 0; col < top; ++i,++col){
        int r = i;
        for(int j = i + 1; j < top; ++j)
            if(fabs(A[j][col]) > fabs(A[r][col])) r = j;
        if(r != i) for(int j = col; j <= top; ++j) swap(A[r][j],A[i][j]);
        if(fabs(A[i][col]) < eps){
            --i;
            continue;
        }
        for(int j = top; j >= col; --j) A[i][j] /= A[i][col];
        for(int k = 0; k < top; ++k) if(k != i)
            for(int j = top; j >= col; --j)
                A[k][j] -= A[k][col] * A[i][j];
    }
    for(; i < top; ++i) if(!(fabs(A[i][top]) < eps)) return false;
    return true;
}
