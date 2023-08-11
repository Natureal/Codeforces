struct Point{
    ld x, y, ag;
    Point(ld a = 0, ld b = 0, ld c = 0): x(a), y(b), ag(c) {}
};

// Direction: counterclockwise = positive
long double Cross(Point st, Point a, Point b){
    Point A(a.x - st.x, a.y - st.y);
    Point B(b.x - st.x, b.y - st.y);
    return A.x * B.y - A.y * B.x;
}

// ag = atan2l(y, x), y = P[i].y - P[1].y, x = P[i].x - P[1].x
// sort(P + 1, P + n + 1, cmp);
bool cmp(Point a, Point b){
    return a.ag < b.ag;
}
