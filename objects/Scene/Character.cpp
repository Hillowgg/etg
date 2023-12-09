#include "Character.h"

Character::Character(std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rot, int hp,
                     float speed) : Object(texture, hitBox, rot), speed(speed), hp(hp) {
};


Character::Character(Character&&other): Object(std::move(other)), speed(std::move(other.speed)),
                                        gun(std::move(other.gun)), hp(std::move(other.hp)) {
}


void Character::draw() const {
    texture->drawById(direction, hitBox, rotation);
    //    Object::draw();
}

void Character::update() {
    if (gun != nullptr) {
        gun->update();
    }
}

void Character::shoot(std::vector<Projectile>&dObjs, const RVector2&to) {
    if (gun == nullptr) {
        return;
    }

    gun->shoot(dObjs, getPos(), to);
}

void Character::addGun(std::shared_ptr<Gun> gun) {
    this->gun = gun;
}

void Character::undoMovement(const RRectangle&collision) {
    auto cc = collision.GetPosition() - collision.GetSize() / 2;
    auto pc = getPos();
    while (collide(collision) and abs(lastMovement.Angle(cc - pc)) > .9) {
        addPos(-lastMovement);
    }
    // if (lastMovement.x != 0) {
    //     addPos({lastMovement.x, 0});
    //     if (collision.CheckCollision(hitBox)) {
    //         addPos({-lastMovement.x, 0});
    //     }
    // }
    // else {
    //     addPos({0, lastMovement.y});
    //     if (collision.CheckCollision(hitBox)) {
    //         addPos({0, -lastMovement.y});
    //     }
    // }
    // auto cc = collision.GetPosition() + collision.GetSize() / 2;
    // auto pc = hitBox.GetPosition() + hitBox.GetSize() / 2;
    // auto vec = pc - cc;
    // // if (std::abs(vec.x) > std::abs(vec.y)) {
    //     if (vec.x > 0) {
    //         addPos({collision.width, 0});
    //     }
    //     else {
    //         addPos({-collision.width, 0});
    //     }
    // // }
    // // else {
    //     if (vec.y > 0) {
    //         addPos({0, -collision.height});
    //     }
    //     else {
    //         addPos({0, collision.height});
    //     }
    // // }
    // addPos(-collision.GetSize());
}

void Character::setHp(int hp_) {
    hp = hp_;
    if (hp <= 0) {
        setToDelete(true);
    }
}

void Character::addHp(int hp_) {
    if (untouchable) return;
    hp += hp_;
    if (hp <= 0) {
        kill();
    }
}

int Character::getHp() const {
    return hp;
}

std::shared_ptr<const Gun> Character::getGun() const {
    return gun;
}

int Character::getMaxHp() const {
    return maxHp;
}

void Character::setMaxHp(int maxHp_) {
    maxHp = maxHp_;
}
