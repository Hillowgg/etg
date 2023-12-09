#pragma once

#include "../../../cmake-build-debug/_deps/raylib_cpp-src/include/raylib-cpp.hpp"
#include "../../Base/Object.h"

enum Target {
    PLAYER,
    ENEMY
};
//todo: make position as a center
struct Projectile: public Object {
    Projectile(std::shared_ptr<TextureBase> texture, RRectangle hitBox, RVector2 direction, Target target, int damage, int speed = 1);

    void update() override;

    void setDamage(int damage) { this->damage = damage; }
    int getDamage() const { return damage; }
    Target getTarget() const { return target; }

private:
    RVector2 direction;
    int damage;
    Target target;
};

