#pragma once
#include <dirent.h>

#include "../Base/Object.h"
#include "Guns/Projectile.h"
#include "Guns/Gun.h"

enum Direction {
    N, E, S, W
};

struct Character: public Object {
    Character(std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rot = 0, int hp = 100, float speed = 400);
    Character(Character&& other);
    Character& operator=(Character&& other)  noexcept {
        hp = std::move(other.hp);
        speed = std::move(other.speed);
        gun = std::move(other.gun);
        Object::operator=(std::move(other));
        return *this;
    };

    void draw() const override;
    void update() override;

    void undoMovement(const RRectangle& collision = RRectangle{0, 0, 0, 0});

    virtual void shoot(std::vector<Projectile>& dObjs, const RVector2& to);

    void addGun(std::shared_ptr<Gun> gun);

    int getHp() const;
    void setHp(int hp_);
    void addHp(int hp_);

    int getMaxHp() const;
    void setMaxHp(int maxHp_);

    std::shared_ptr<const Gun> getGun() const;

    virtual void kill() {setToDelete(true);}

protected:
    bool movementBlocked = false;
    RVector2 lastMovement;
    float speed;
    Direction direction = Direction::N;

    int hp;
    int maxHp = 100;
    bool untouchable;
    std::shared_ptr<Gun> gun;
};
