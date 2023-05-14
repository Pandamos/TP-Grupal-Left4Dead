#ifndef RECTANGLE_H
#define RECTANGLE_H
struct Rectangle;

#include "Point.h"

struct Rectangle {
    int x1;
    int x2;
    int y1;
    int y2;

    Rectangle();
    Rectangle(int x1, int x2, int y1, int y2);

    void move(const int xdist, const int ydist);
    bool contains(const Point &point) const;
    bool collides(const Rectangle &other) const;
    bool in_shoot_range(const Rectangle &shooter) const;
    int width() const;
    int heigth() const;
};
#endif // RECTANGLE_H
