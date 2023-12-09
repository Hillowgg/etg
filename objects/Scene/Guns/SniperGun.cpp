#include "SniperGun.h"
#include "../../../utils/Textures.h"

SniperGun::SniperGun(Target target):
Gun(Textures::getTexture("sniper_bullet"),Textures::getTexture("sniper_gun"), target, 70, 5, 60, 2000) {
    setReloadTime(3);
}

void SniperGun::shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) {
    if (GetTime() - lastShot < fireDelay) {
        return;
    }
    if (reloading or ammo == 0) {
        return;
    }
    ammo--;
    lastShot = GetTime();
    RVector2 size = {60, 60};
    vec.push_back(std::move(
        Projectile(bulletTexture, {from - size / 2, size}, to - from, target, damage, speed)));
}