#include "Entity.h"
#include "../../../../focuses/Scene.h"
#include  "../../../../utils/Textures.h"
#include "../../Guns/ShotGun.h"



Entity::Entity(std::shared_ptr<TextureBase> texture, RRectangle hitBox) : Object(texture, hitBox, 0) {};

Entity::Entity(Entity&&other) : Object(std::move(other)) {}


void Entity::update() {
    auto p = Scene::instance().getPlayer();
    auto c = Scene::instance().getCamera();
    if (collide(c->getWorldCursorPos()) and p->getPos().Distance(getPos()) < 150 ) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            p->addGun(std::make_shared<ShotGun>(Target::ENEMY));
            setToDelete(true);
        }

    }
}
