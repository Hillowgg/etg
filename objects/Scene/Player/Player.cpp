#include <filesystem>
#include <iostream>
#include "Player.h"

#include "../../../App.h"

Player::Player(std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rot, int hp, float speed): Character(
    texture, hitBox, rot, hp, speed) {
}

void Player::handleMovement() {
    if (movementBlocked) {
        return;
    }
    RVector2 newPos = {0, 0};
    if (IsKeyDown(KEY_W)) {
        newPos += RVector2(0, -1);
        //        texture->setAnim(Direction::N);
        direction = Direction::N;
    }
    else if (IsKeyDown(KEY_S)) {
        newPos += RVector2(0, 1);
        //        texture->setAnim(Direction::S);
        direction = Direction::S;
    }

    if (IsKeyDown(KEY_D)) {
        newPos += RVector2(1, 0);
        //        texture->setAnim(Direction::E);
        direction = Direction::E;
    }
    else if (IsKeyDown(KEY_A)) {
        newPos += RVector2(-1, 0);
        //        texture->setAnim(Direction::W);
        direction = Direction::W;
    }

    if (IsKeyPressed(KEY_LEFT_SHIFT)) {
        dash();
    }

    newPos = newPos.Normalize() * speed * GetFrameTime();
    if (newPos != RVector2(0, 0)){
        lastMovement = newPos;
    }

    addPos(newPos);
}

void Player::dash() {
    if (!dashing and GetTime() - dashStart > 1) {
        dashStart = GetTime();
        dashing = true;
        untouchable = true;
    }
}



void Player::update() {
    if (dashing and GetTime() - dashStart < .3) {
        auto move = lastMovement * 1.5;
        addPos(move);
        lastMovement = move;
    } else {
        dashing = false;
        movementBlocked = false;
        untouchable = false;
    }
    handleMovement();
    Character::update();
}

void Player::kill() {
    setToDelete(true);
    Scene::instance().reset();
}
