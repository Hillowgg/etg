#pragma once
#include "Gun.h"



struct PistolGun: public Gun {
    PistolGun(Target);
    void shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) override;
};
