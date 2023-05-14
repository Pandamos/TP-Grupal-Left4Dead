#ifndef QUAD_THREE_H
#define QUAD_THREE_H
class QuadThree;

#include <list>
#include "Rectangle.h"
#include "general/GameInstance.h"

class QuadThree {
    Rectangle area;
    std::list<GameInstance*> contents;
    QuadThree* childs[4];

    public:
    QuadThree();
    ~QuadThree();
    void add_instance();
};
#endif  // QUAD_THREE_H
