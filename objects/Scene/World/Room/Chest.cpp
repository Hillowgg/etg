#include "Chest.h"

#include "../../../../focuses/Scene.h"

Chest::Chest(std::shared_ptr<TextureBase> texture, RRectangle hitBox, Entity entity):
Object(texture, hitBox), entity(std::move(entity)) {}

void Chest::update() {
    auto p = Scene::instance().getPlayer();
    auto c = Scene::instance().getCamera();
    if (collide(c->getWorldCursorPos()) and p->getPos().Distance(getPos()) < 150) {
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            texture->setAnim(1);
            Scene::instance().addEntity(entity);
        }
    }
}