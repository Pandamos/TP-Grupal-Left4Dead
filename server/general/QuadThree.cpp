#include "QuadThree.h"

#define QUT_NOT_HAS_CHILDS !this->childs[0]
#define QUT_HAS_CHILDS this->childs[0]

QuadThree::QuadThree(const Rectangle& room_size) : area(room_size) {
    this->childs[0] = nullptr;
    this->parent = nullptr;
}

QuadThree::~QuadThree() {
    if (QUT_NOT_HAS_CHILDS)
        return;

    for (auto child : this->childs)
        delete child;
}

void QuadThree::insert(GameInstance* new_instance) {
    if (this->contents.size() < QUT_INSTANCE_LIMIT 
    || this->area.width() == 1 
    || this->area.heigth() == 1) {
        this->contents.push_back(new_instance);
    } else {
        if (QUT_NOT_HAS_CHILDS)
            this->subdivide();

        for (auto child : this->childs) {
            if (child->area.contains(new_instance->position))
                child->insert(new_instance);
        }
    }
}

void QuadThree::remove(GameInstance* new_instance) {
    this->contents.remove(new_instance);

    if (QUT_NOT_HAS_CHILDS)
        return;

    for (auto child : this->childs) {
        if (child->area.contains(new_instance->position))
            child->remove(new_instance);
    }
}

void QuadThree::get_instances(const Rectangle &area, std::list<GameInstance*> &result) const {
    for (auto inst : this->contents) {
        result.push_back(inst);
    }
    for (auto child : this->childs) {
        if (child->area.collides(area))
            child->get_instances(area,result);
    }
}

void QuadThree::subdivide() {
    this->childs[QUT_ROSE_NE] = new QuadThree(Rectangle(
        this->area.x1 +this->area.width()/2, this->area.x2,
        this->area.y1, this->area.y1+this->area.heigth()/2
    ));
    this->childs[QUT_ROSE_NW] = new QuadThree(Rectangle(
        this->area.x1, this->area.x1+this->area.width()/2,
        this->area.y1, this->area.y1+this->area.heigth()/2
    ));
    this->childs[QUT_ROSE_SE] = new QuadThree(Rectangle(
        this->area.x1 +this->area.width()/2, this->area.x2,
        this->area.y1 +this->area.heigth()/2, this->area.y2
    ));
    this->childs[QUT_ROSE_SW] = new QuadThree(Rectangle(
        this->area.x1, this->area.x1+this->area.width()/2,
        this->area.y1 +this->area.heigth()/2, this->area.y2
    ));

    for (auto child : this->childs) {
        child->parent = this;
    }
}

void QuadThree::update() {
    if (QUT_HAS_CHILDS) {
        for (auto child : this->childs) {
            child->update(); 
            delete child;
        }
    }

    if (parent) {
        for (auto gobj : this->contents)
            this->parent->move_instance_up_three(gobj);
        this->contents.clear();
    } else {
        while(this->contents.size() >= QUT_INSTANCE_LIMIT) {
            GameInstance* inst = this->contents.back();
            this->insert(inst);
            this->contents.pop_back();
        }
    }
}

void QuadThree::move_instance_up_three(GameInstance *inst) {
    this->contents.push_back(inst);
}