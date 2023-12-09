#pragma once

#include <raylib-cpp.hpp>
#include "Projectile.h"
#include "../../Base/TextureBase.h"


struct Gun {
    explicit Gun(std::shared_ptr<TextureBase> bulletTexture, Target target, double firerate);
    explicit Gun(std::shared_ptr<TextureBase> bulletTexture, std::shared_ptr<TextureBase> gunTexture, Target target, double firerate, unsigned ammo, int damage, double speed);

    virtual void shoot(std::vector<Projectile>& vec, const RVector2& from, const RVector2& to);
    double getSpeed() const;
    void setSpeed(double);

    void setAmmo(unsigned);
    unsigned getAmmo() const;

    void setMaxAmmo(unsigned);
    unsigned getMaxAmmo() const;

    void setReloadTime(double reloadTime) {
        this->reloadTime = reloadTime;
    }

    std::shared_ptr<TextureBase> getGunTexture() const {
        return gunTexture;
    }

    virtual void reload();

    virtual void update();


protected:
    std::shared_ptr<TextureBase> bulletTexture;
    std::shared_ptr<TextureBase> gunTexture;
    Target target;
    int damage;
    double reloadStart;
    double reloadTime = 2;
    bool reloading;

    unsigned ammo;
    unsigned maxAmmo = 1;

    double lastShot;
    double fireRate;
    double fireDelay;
    double speed = 100;
};