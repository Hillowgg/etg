#include "Gun.h"


#include <utility>
#include <iostream>


Gun::Gun(std::shared_ptr<TextureBase> bulletTexture, Target target, double firerate):
bulletTexture(std::move(bulletTexture)), target(target), speed(100), fireRate(firerate) {
    fireDelay = 60 / fireRate;
}

Gun::Gun(std::shared_ptr<TextureBase> bulletTexture,std::shared_ptr<TextureBase> gunTexture,Target target,double firerate,unsigned ammo,int damage, double speed):
bulletTexture(std::move(bulletTexture)),gunTexture(gunTexture), speed(speed), target(target), fireRate(firerate), ammo(ammo),
maxAmmo(ammo), damage(damage) {
    fireDelay = 60 / fireRate;
}

void Gun::shoot(std::vector<Projectile>&vec, const RVector2&from, const RVector2&to) {

}

double Gun::getSpeed() const {
    return speed;
}

void Gun::setSpeed(double speed_) {
    speed = speed_;
}

void Gun::setAmmo(unsigned ammo_) {
    ammo = ammo_;
}

unsigned Gun::getAmmo() const {
    return ammo;
}

void Gun::setMaxAmmo(unsigned maxAmmo_) {
    maxAmmo = maxAmmo_;
}

unsigned Gun::getMaxAmmo() const {
    return maxAmmo;
}

void Gun::update() {
    if (ammo == 0) {
        reload();
    }
}

void Gun::reload() {
    if (ammo == 0) {
        if (!reloading) {
            reloading = true;
            reloadStart = GetTime();
        }
        if (GetTime() - reloadStart > reloadTime) {
            reloading = false;
            ammo = maxAmmo;
        }
    }
}