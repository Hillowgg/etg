#pragma once
#include "../../../Base/Object.h"
#include "Entity.h"


struct Chest: public Object {
    Chest(std::shared_ptr<TextureBase> texture, RRectangle hitBox, Entity entity);
    Chest(Chest&& chest): Object(std::move(chest)), entity(std::move(chest.entity)) {};
    Chest& operator=(Chest&& chest) {
        Object::operator=(std::move(chest));
        entity = std::move(chest.entity);
        return *this;
    }
    void update() override;

private:
    Entity entity;
};
