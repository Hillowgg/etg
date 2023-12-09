#pragma once
#include "Gun.h"



struct SniperGun: public Gun {
    SniperGun(Target);
    void shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) override;
};