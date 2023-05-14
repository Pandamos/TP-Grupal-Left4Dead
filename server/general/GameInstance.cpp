#include "GameInstance.h"

//GameInstance::GameInstance() {}
void GameInstance::move(const int xdist, const int ydist) {
    this->position.x += xdist;
    this->position.y += ydist;
    this->collision_box.move(xdist, ydist);
}

bool GameInstance::collides(const Rectangle &box) const {
    return this->collision_box.collides(box);
}