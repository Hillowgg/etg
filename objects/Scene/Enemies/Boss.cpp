#include "Boss.h"
#include "../../../utils/Textures.h"
#include "../../../focuses/Scene.h"


Boss::Boss(std::shared_ptr<TextureBase> texture, const RVector2& pos, int hp, double speed):
Character(texture, {0, 0, 150, 200}, 0, hp, speed), spawnPoint(pos) {
    setPos(pos);
}

Boss::Boss(Boss&& other): Character(std::move(other)), spawnPoint(other.spawnPoint),
movement(other.movement), attackCounter(other.attackCounter), attackDelay(other.attackDelay), lastAttack(other.lastAttack) {
}

Boss& Boss::operator=(Boss&& other) noexcept {
    Character::operator=(std::move(other));
    spawnPoint = other.spawnPoint;
    movement = other.movement;
    attackCounter = other.attackCounter;
    attackDelay = other.attackDelay;
    lastAttack = other.lastAttack;
    return *this;
}

void Boss::smallAttack(std::vector<Projectile>&dObjs, const RVector2&to) {
    dObjs.push_back(std::move(Projectile(Textures::getTexture("pistol_bullet"), {getPos(), {45, 45}}, to - getPos(), Target::PLAYER, 30, 350)));
}

void Boss::bigAttack(std::vector<Projectile>&dObjs, const RVector2&to) {
    dObjs.push_back(std::move(Projectile(Textures::getTexture("fireball"), {getPos(), {150, 150}}, to - getPos(), Target::PLAYER, 80, 300)));
}

void Boss::waveAttack(std::vector<Projectile>&dObjs, const RVector2&to) {
    for (float ang = -0.5; ang < .5; ang += 0.1) {
        dObjs.push_back(std::move(
            Projectile(Textures::getTexture("sniper_bullet"), {getPos(), {80, 80}}, (to - getPos()).Rotate(ang), Target::PLAYER, 20, 300)));
    }
}
void Boss::circleAttack(std::vector<Projectile>&dObjs, const RVector2&to) {
    for (float ang = 0; ang < 10; ang += .1) {
        dObjs.push_back(std::move(
            Projectile(Textures::getTexture("pistol_bullet"), {getPos(), {60, 60}}, (to - getPos()).Rotate(ang), Target::PLAYER, 20, 320)));
    }
}


void Boss::shoot(std::vector<Projectile>&dObjs, const RVector2&to) {
    if (attackCounter % 40 == 0) {
        circleAttack(dObjs, to);
    }
    if (attackCounter % 50 == 0) {
        waveAttack(dObjs, to);
    } else if (attackCounter % 10 == 0) {
        bigAttack(dObjs, to);
    } else {
        smallAttack(dObjs, to);
    }
    attackCounter++;
}


void Boss::update() {
    newMovement(100);
    if (GetTime() - lastAttack > attackDelay) {
        shoot(Scene::instance().getProjectiles(), Scene::instance().getPlayer()->getPos());
        lastAttack = GetTime();
    }

}

void Boss::newMovement(float r) {
    static float t = 0;
    float x = r * cos(t) + spawnPoint.x;
    float y = r * sin(t) + spawnPoint.y;
    t += 0.01 * speed;
    setPos({x, y});
}

