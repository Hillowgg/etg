#include "Projectile.h"


void Projectile::update() {
    setPos(getPos() + direction * GetFrameTime());
    texture->update();
}

Projectile::Projectile(std::shared_ptr<TextureBase> texture, RRectangle hitBox, RVector2 direction, Target target, int damage, int speed):
Object(texture, hitBox), damage(damage), target(target) {
    if (speed != 1) {
        this->direction = direction.Normalize() * speed;
    } else {
        this->direction = direction;
    }
}
