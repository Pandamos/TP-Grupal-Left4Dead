#ifndef QUAD_THREE_H
#define QUAD_THREE_H
class QuadThree;

#include <list>
#include "Rectangle.h"
#include "general/GameInstance.h"
#define QUT_INSTANCE_LIMIT 3
#define QUT_ROSE_NW 0
#define QUT_ROSE_NE 1
#define QUT_ROSE_SW 2
#define QUT_ROSE_SE 3

class QuadThree {
    Rectangle area;
    QuadThree* childs[4];
    std::list<GameInstance*> contents;

    void subdivide();
    public:
    QuadThree(const Rectangle &room_size);
    ~QuadThree();
    void insert(GameInstance* new_instance);
    void remove(GameInstance* new_instance);
    void inside_area(const Rectangle &area, std::list<GameInstance*> &result) const;
};
#endif  // QUAD_THREE_H
