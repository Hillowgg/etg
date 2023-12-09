#include "ShotGun.h"
#include "../../../utils/Textures.h"


ShotGun::ShotGun(Target target): Gun(Textures::getTexture("shotgun_bullet"),Textures::getTexture("shotgun"), target, 300, 10, 10, 1500) {
    setReloadTime(1);
}

void ShotGun::shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) {
    if (GetTime() - lastShot < fireDelay) {
        return;
    }
    if (ammo == 0) {
        return;
    }
    ammo--;
    reloading = false;
    lastShot = GetTime();
    RVector2 size = {30, 30};

    for (float i = -5; i < 5; i += 1) {
        vec.push_back(std::move(
            Projectile(bulletTexture, {from - size / 2, size}, (to - from).Rotate(i / 20), target, damage, speed)));
    }
}

void ShotGun::update() {
    reload();
}

void ShotGun::reload() {
    static unsigned counter = 0;

    if (ammo == 0 and !reloading) {
        reloading = true;
        reloadStart = GetTime();
    }
    if (GetTime() - reloadStart > reloadTime and reloading) {
        ammo++;
        counter++;
        reloadStart = GetTime();
    }
    if (counter == maxAmmo) {
        counter = 0;
        reloading = false;
    }
}
