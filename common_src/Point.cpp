#include <cmath>
#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

float Point::distance(const Point &other) const {
    int xdist = this->x - other.x;
    int ydist = this->y - other.y;

    return std::sqrt(xdist*xdist + ydist*ydist);
}

