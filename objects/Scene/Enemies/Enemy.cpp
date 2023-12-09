#include "Enemy.h"

#include <iostream>
#include <random>

#include "../../../focuses/Scene.h"


Enemy::Enemy(
        std::shared_ptr<TextureBase> texture,
        RRectangle hitBox,
        double rot,
        int hp,
        double speed): Character(texture, hitBox, rot, hp, speed) {
}
Enemy::Enemy(Enemy&& other): Character(std::move(other)) {}

void Enemy::setMovement(RVector2) {
}

void Enemy::newMovement(int delta) {
    if (movementCounter % delta == 0) {
        movement = RVector2(1, 1).Rotate(rand() % 360);
        lastMovement = movement;
    }
    ++movementCounter %= delta;
}


void Enemy::update() {
    newMovement();
    setPos(getPos() + movement.Normalize() * speed);
    gun->shoot(Scene::instance().getProjectiles(), getPos(), Scene::instance().getPlayer()->getPos());
    gun->update();
}




