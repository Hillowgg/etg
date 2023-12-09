#include "PistolGun.h"
#include "../../../utils/Textures.h"
#include <iostream>


PistolGun::PistolGun(Target target):
Gun(Textures::getTexture("pistol_bullet"), Textures::getTexture("pistol_gun"), target, 350, 10, 20, 800) {

}

void PistolGun::shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) {
    if (GetTime() - lastShot < fireDelay) {
        return;
    }
    if (reloading or ammo == 0) {
        return;
    }
    ammo--;
    lastShot = GetTime();
    RVector2 size = {45, 45};
    vec.push_back(std::move(
        Projectile(bulletTexture, {from - size / 2, size}, to - from, target, damage, speed)));
}
