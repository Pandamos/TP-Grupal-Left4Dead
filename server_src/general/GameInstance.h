#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H
class GameInstance;

#include "../../common_src/Point.h"
#include "../../common_src/Rectangle.h"

class GameInstance {
    public:
    Point position;
    Rectangle collision_box;
    explicit GameInstance(int width, int height);
    explicit GameInstance(int width, int height, int x, int y);
    void move(const int xdist, const int ydist);
    bool collides(const Rectangle &box) const;
};
#endif  // GAME_INSTANCE_H
