#ifndef QUAD_THREE_H
#define QUAD_THREE_H
class QuadThree;

#include <list>
#include "Rectangle.h"
#include "general/GameInstance.h"

class QuadThreeNode {
    Rectangle area;
    std::list<GameInstance*> contents;
    Rectangle* childs[4];

    public:
    QuadThreeNode();
    ~QuadThreeNode();
    void add_instance();
};

class QuadThree {
    
};


#endif  // QUAD_THREE_H
