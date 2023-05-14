#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H
class GameInstance;

#include "../common/Point.h"
#include "../common/Rectangle.h"

class GameInstance {
    protected:
    Point position;
    Rectangle collision_box;

    public:
    //GameInstance();
    void move(const int xdist, const int ydist);
    bool collides(const Rectangle &box) const;
};
#endif  // GAME_INSTANCE_H
