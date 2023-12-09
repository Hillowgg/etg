#pragma once

#include "raylib-cpp.hpp"
#include <utility>
#include "TextureBase.h"


struct Object {
    Object(std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rotation = 0):
            texture(texture), hitBox(hitBox), rotation(rotation) {};

    Object(const std::string& texturePath, RRectangle hitBox, float rotation = 0):
    texture(std::make_shared<TextureBase>(texturePath)), hitBox(hitBox), rotation(rotation) {}

    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;

    Object(Object&& other) noexcept: texture(std::move(other.texture)), hitBox(std::move(other.hitBox)), rotation(std::move(other.rotation)), toDelete_(std::move(other.toDelete_)) {}
    Object& operator=(Object&& other) noexcept {
        texture = std::move(other.texture);
        hitBox = std::move(other.hitBox);
        rotation = std::move(other.rotation);
        toDelete_ = std::move(other.toDelete_);
        return *this;
    }


    virtual void draw() const;
    virtual void update() {};

    RVector2 getPos() const;

    void setPos(RVector2 position);
    void addPos(RVector2 vec);

    RVector2 getSize() { return hitBox.GetSize();}

    float getRotation() const { return rotation; }

    void setRotation(float rotation_) { rotation = rotation_; }

    bool collide(const Object& other) const;
    bool collide(const RVector2& vec) const;
    bool collide(const RRectangle& rec) const;
    RRectangle getCollision(const Object& other) const;

    bool toDelete() const { return toDelete_; }
    void setToDelete(bool _toDelete) { toDelete_ = _toDelete; }
protected:
    bool toDelete_ = false;
    RRectangle hitBox;
    float rotation;
    std::shared_ptr<TextureBase> texture;
};


