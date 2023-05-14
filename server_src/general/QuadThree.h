#ifndef QUAD_THREE_H
#define QUAD_THREE_H
class QuadThree;

#include <list>
#include "../../common/Rectangle.h"
#include "GameInstance.h"
#define QUT_INSTANCE_LIMIT 3
#define QUT_ROSE_NW 0
#define QUT_ROSE_NE 1
#define QUT_ROSE_SW 2
#define QUT_ROSE_SE 3

class QuadThree {
    Rectangle area;
    QuadThree* parent;
    QuadThree* childs[4];
    std::list<GameInstance*> contents;

    void subdivide();
    void move_instance_up_three(GameInstance* loaded);
    public:
    explicit QuadThree(const Rectangle &room_size);
    ~QuadThree();
    void update();
    void insert(GameInstance* new_instance);
    void remove(GameInstance* new_instance);
    void get_instances(const Rectangle &area, std::list<GameInstance*> &result) const;
};
#endif  // QUAD_THREE_H
