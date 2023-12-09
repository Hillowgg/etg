#pragma once
#include "../../../Base/Object.h"


struct Entity: public Object {
    Entity(std::shared_ptr<TextureBase> texture, RRectangle hitBox);
    Entity(Entity&& other);
    Entity& operator=(Entity&& entity) {
        Object::operator=(std::move(entity));
        return *this;
    }
    void update() override;
private:

};
