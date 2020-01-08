// The range of bit is [1, maxn]. Do not store any value at index 0.
// Notice that values in c[] are set to 0 initially.
const int maxn = ;

template<class T>
struct BIT_max{
    T c[maxn];
    BIT_max(){ clear(); }
    inline void clear(){ memset(c, 0, sizeof(c)); }
    inline T lowbit(T &x){ return x & (-x); }
    inline void add(int x, T d){
        while(x <= maxn){
            c[x] = max(c[x], d);
            x += lowbit(x);
        }
    }
    inline T get(int x){
        T res = 0;
        while(x){
            res = max(res, c[x]);
            x -= lowbit(x);
        }
        return res;
    }
};
