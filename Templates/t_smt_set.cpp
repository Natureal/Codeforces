const int maxn = ;

template<class T>
struct SMT{
    T t[maxn << 2], st[maxn << 2];
    void clear(){
        MEM(t, 0);
	MEM(st, 0);
    }
    void push_down(int p){
	if(st[p]){
	    st[p << 1] = max(st[p << 1], st[p]);
	    t[p << 1] = max(t[p << 1], st[p]);
	    st[p << 1|1] = max(st[p << 1|1], st[p]);
            t[p << 1|1] = max(t[p << 1|1], st[p]);
	    st[p] = 0;
	}
    }
    void update(int a, int b, T c, int p, int l, int r){
        if(a <= l && r <= b){
            t[p] = max(t[p], c);
	    st[p] = max(st[p], c);
            return;
        }
        int mid = getmid(l, r);
	push_down(p);
        if(a <= mid) update(a, b, c, p << 1, l, mid);
        if(b > mid)  update(a, b, c, p << 1|1, mid + 1, r);
        t[p] = max(t[p << 1], t[p << 1|1]);
    }
    T query(int a, int b, int p, int l, int r){
        if(a <= l && r <= b){
            return t[p];
        }
        int mid = getmid(l, r);
	push_down(p);
        T res = 0; // should be -INF
        if(a <= mid) res = max(res, query(a, b, p << 1, l, mid));
        if(b > mid)  res = max(res, query(a, b, p << 1|1, mid + 1, r));
        return res;
    }
};

SMT<int> smt;

