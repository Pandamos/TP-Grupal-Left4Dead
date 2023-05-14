#ifndef POINT_H
#define POINT_H
struct Point;

struct Point {
    int x;
    int y;

    Point();
    Point(int x, int y);
    float distance(const Point &other) const;
};
#endif // POINT_H
