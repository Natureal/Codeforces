// The range of bit is [1, maxn]. Do not store any value at index 0.
const int maxn = ;

template<class T>
struct BIT{
    T c[maxn];
    BIT(){ clear(); }
    inline void clear(){ memset(c, 0, sizeof(c)); }
    inline int lowbit(int x){ return x & (-x); }
    inline void add(int x, T d){
        while(x < maxn){
            c[x] += d;
            x += lowbit(x);
        }
    }
    inline T get(int x){
        T res = 0;
        while(x){
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    }
};
