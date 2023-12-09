#pragma once
#include "raylib-cpp.hpp"
#include "../Character.h"
#include "../Guns/Gun.h"


struct Player : public Character {
    Player(std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rot = 0, int hp = 100, float speed = 400);
    void handleMovement();
    void update() override;
    void dash();
    void kill() override;
private:
    bool dashing;
    double dashStart;
};
