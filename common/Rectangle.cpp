#include "Rectangle.h"

Rectangle::Rectangle() : x1(0), x2(0), y1(0), y2(0) {};

Rectangle::Rectangle(int x1, int x2, int y1, int y2) {
    if (x1 < x2) {
        this->x1 = x1;
        this->x2 = x2;
    } else {
        this->x1 = x2;
        this->x2 = x1;
    }

    if (y1 < y2) {
        this->y1 = y1;
        this->y2 = y2;
    } else {
        this->y1 = y2;
        this->y2 = y1;
    }
}

void Rectangle::move(const int xdist, const int ydist) {
    this->x1 += xdist;
    this->x2 += xdist;
    this->y1 += ydist;
    this->y2 += ydist;
}

bool Rectangle::collides(const Rectangle &other) const {
    return this->x1 < other.x2 && this->x2 > other.x1 && this->y1 > other.y2 && this->y2 < other.y1;
}

bool Rectangle::in_shoot_range(const Rectangle &shooter) const {
    return this->y1 > shooter.y2 && this->y2 < shooter.y1;
}
