struct Point {
    int x;
    int y;

    Point();
    Point(int x, int y);
    float distance(const Point &other) const;
}