#include "Object.h"

bool Object::collide(const Object&other) const {
    return hitBox.CheckCollision(other.hitBox);
}

bool Object::collide(const RVector2&vec) const {
    return hitBox.CheckCollision(vec);
}

bool Object::collide(const RRectangle& rec) const {
    return hitBox.CheckCollision(rec);
}

RRectangle Object::getCollision(const Object&other) const {
    return hitBox.GetCollision(other.hitBox);
}

void Object::draw() const { texture->draw(hitBox, rotation); }

RVector2 Object::getPos() const {
    return hitBox.GetPosition() + hitBox.GetSize() / 2;
}

void Object::setPos(RVector2 position) { hitBox.SetPosition(position - hitBox.GetSize() / 2); }

void Object::addPos(RVector2 vec) {
    setPos(getPos() + vec);
}
