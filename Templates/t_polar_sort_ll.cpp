struct Point{
    ll x, y;
    Point(ll a = 0, ll b = 0): x(a), y(b) {}
    bool operator < (const Point &b) const{
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
};

// Direction: counterclockwise = positive
ll Cross(Point st, Point a, Point b){
    Point A(a.x - st.x, a.y - st.y);
    Point B(b.x - st.x, b.y - st.y);
    return A.x * B.y - A.y * B.x;
}

bool cmp(Point a, Point b){
    Point st = P[1];
    Point A(a.x - st.x, a.y - st.y);
    Point B(b.x - st.x, b.y - st.y);
    // Quadrant judgement
    bool bh1 = A < Point(0, 0), bh2 = B < Point(0, 0);
    if(bh1 != bh2) return bh1 < bh2;
    return Cross(st, a, b) > 0;
}
