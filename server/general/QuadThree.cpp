#include "QuadThree.h"

QuadThree::QuadThree(const Rectangle& room_size) : area(room_size) {
    this->childs[0] = nullptr;
}

void QuadThree::insert(GameInstance* new_instance) {
    if (this->contents.size() < QUT_INSTANCE_LIMIT) {
        this->contents.push_back(new_instance);
    } else {
        if (!this->childs[0])
            this->subdivide();

        for (auto child : this->childs) {
            if (child->area.contains(new_instance->position))
                child->insert(new_instance);
        }
    }
}

void QuadThree::remove(GameInstance* new_instance) {
    this->contents.remove(new_instance);

    if (!this->childs[0]) 
        return;

    for (auto child : this->childs) {
        if (child->area.contains(new_instance->position))
            child->remove(new_instance);
    }
}

void QuadThree::inside_area(const Rectangle &area, std::list<GameInstance*> &result) const {
    for (auto inst : this->contents) {
        result.push_back(inst);
    }
    for (auto child : this->childs) {
        if (child->area.collides(area))
            child->inside_area(area,result);
    }
}

void QuadThree::subdivide() {
    this->childs[QUT_ROSE_NE] = new QuadThree(Rectangle(
        this->area.x1+this->area.width()/2, this->area.x2,
        this->area.y1, this->area.y1+this->area.heigth()/2
    ));
    this->childs[QUT_ROSE_NW] = new QuadThree(Rectangle(
        this->area.x1, this->area.x1+this->area.width()/2,
        this->area.y1, this->area.y1+this->area.heigth()/2
    ));
    this->childs[QUT_ROSE_SE] = new QuadThree(Rectangle(
        this->area.x1+this->area.width()/2, this->area.x2,
        this->area.y1+this->area.heigth()/2, this->area.y2
    ));
    this->childs[QUT_ROSE_SW] = new QuadThree(Rectangle(
        this->area.x1, this->area.x1+this->area.width()/2,
        this->area.y1+this->area.heigth()/2, this->area.y2
    ));
}
