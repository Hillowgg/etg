#pragma once
#include "Gun.h"


struct ShotGun: public Gun {
    ShotGun(Target);
    void shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) override;
    void reload() override;
    void update() override;
};

