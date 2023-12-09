#pragma once
#include "../Character.h"


struct Boss: public Character {
    Boss(std::shared_ptr<TextureBase> texture, const RVector2& pos, int hp, double speed = 100);
    Boss(Boss&& other);
    Boss& operator=(Boss&&) noexcept;
    void update() override;
    void shoot(std::vector<Projectile>& dObjs, const RVector2& to) override;
private:
    void waveAttack(std::vector<Projectile>& dObjs, const RVector2& to);
    void bigAttack(std::vector<Projectile>& dObjs, const RVector2& to);
    void smallAttack(std::vector<Projectile>& dObjs, const RVector2& to);
    void circleAttack(std::vector<Projectile>& dObjs, const RVector2& to);
    void newMovement(float r);
    RVector2 spawnPoint;
    RVector2 movement;
    int attackCounter;
    double attackDelay = .2;
    double lastAttack;
};
