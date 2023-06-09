#include "GameInstance.h"

GameInstance::GameInstance(int width, int height)
: position(width / 2, height / 2) 
, collision_box(0, width, 0, height)
{}

GameInstance::GameInstance(int width, int height, int x, int y)
: position(x, y) , collision_box(0, width, 0, height) {
    this->collision_box.move(x-width/2, y-height/2);
}


void GameInstance::move(const int xdist, const int ydist) {
    this->position.x += xdist;
    this->position.y += ydist;
    this->collision_box.move(xdist, ydist);
}

bool GameInstance::collides(const Rectangle &box) const {
    return this->collision_box.collides(box);
}
