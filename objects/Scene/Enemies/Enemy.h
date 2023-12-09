#pragma once
#include "../Guns/Gun.h"
#include "../Character.h"


struct Enemy: public Character {
    Enemy(std::shared_ptr<TextureBase> texture, RRectangle hitBox, double rot, int hp, double speed = 100);
    Enemy(Enemy&& other);
    Enemy& operator=(Enemy&& other) noexcept {
        Character::operator=(std::move(other));
        return *this;
    };

    void update() override;
    void setMovement(RVector2);
    void newMovement(int delta = 100);
protected:
    RVector2 movement;
    int movementCounter = 0;
};
