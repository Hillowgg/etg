#include <iostream>
#include "Scene.h"

#include "../objects/Base/AutoAnimTexture.h"
#include "../objects/Scene/Enemies/Enemy.h"
#include "../utils/Textures.h"
#include "../objects/Scene/Guns/PistolGun.h"
#include "../objects/Scene/Guns/ShotGun.h"
#include "../objects/Scene/Guns/SniperGun.h"
#include "../objects/Scene/Enemies/Boss.h"

Scene::Scene() {
    reset();
}

void Scene::reset() {
    npcs.clear();
    projectiles.clear();
    entities.clear();
    auto player_texture = Textures::getTexture("player");
    player = std::make_shared<Player>(player_texture, RRectangle{0, 0, 100, 100});
    player->setPos({0, 0});
    std::vector<RRectangle> textures;

    textures.reserve(4);
    for (int i = 0; i < 4; i++) {
        textures.emplace_back(304 + 16 * i, 16 * 2, 16, 16);
    }

    player->addGun(std::make_shared<SniperGun>(Target::ENEMY));


    camera = std::make_shared<CameraController>(player->getPos(), 50, 0.01);
    world = std::make_unique<World>();
    auto txt = Textures::getTexture("trigger");
    txt->setTransparency(100);
}



void Scene::update() {
    handleInputs();
    world->update();
    player->update();
    for (auto&obj: npcs) {
        obj->update();
        if (world->collide(*obj)) {
            obj->undoMovement();
        }
    }
    if (world->collide(*player)) {

        auto collision = world->getCollision(*player);
        player->undoMovement(collision);
    }

    for (auto& p: projectiles) {
        p.update();
        if (world->collide(p)) {
            p.setToDelete(true);
        }
    }

    for (auto & proj : projectiles) {
        if (proj.getTarget() == Target::PLAYER) {
            if (proj.collide(*player)) {
                proj.setToDelete(true);
                player->addHp(-proj.getDamage());
                break;
            }
        } else {
            for (auto & npc : npcs) {
                if (proj.collide(*npc)) {
                    proj.setToDelete(true);
                    npc->addHp(-proj.getDamage());
                    break;
                }
            }
        }
    }
    for (auto& entity: entities) {
        entity.update();
    }

    std::erase_if(entities, [](const Entity& p) {
        return p.toDelete();
    });

    std::erase_if(projectiles, [](const Projectile& p) {
        return p.toDelete();
    });


    std::erase_if(npcs, [](std::unique_ptr<Character>& e) {
        return e->toDelete();
    });


}

void Scene::draw() const {
    camera->setTarget(player->getPos());
    camera->begin();

    world->draw();

    player->draw();
    for (const auto&obj: projectiles) {

        obj.draw();
    }

    for (const auto&obj: npcs) {
        obj->draw();
    }

    for (const auto& entity: entities) {
        entity.draw();
    }

    camera->end();
    hud->draw();
}

void Scene::focus() {
}

void Scene::unfocus() {
}

void Scene::spawnEnemy(const RVector2&pos) {
    auto texture = Textures::getTexture("enemy");

    RRectangle hb = {0, 0, 100, 100};
    hb.SetPosition(pos);
    Enemy e(texture, hb, 0, 100, 1);
    e.addGun(std::make_shared<ShotGun>(Target::PLAYER));
    npcs.push_back(std::make_unique<Enemy>(std::move(e)));
}

void Scene::spawnBoss(const RVector2& pos) {
    auto texture = Textures::getTexture("enemy");
    Boss b(texture, pos, 1000, 1);
    npcs.push_back(std::make_unique<Boss>(std::move(b)));
}


void generateEnemy(std::shared_ptr<Player> p, std::vector<Enemy>&npcs, RVector2 mouse) {
    auto texture = Textures::getTexture("enemy");

    auto gt = Textures::getTexture("fireball");
    Gun g2(gt, Target::PLAYER, 100000);

    RRectangle hb = {0, 0, 100, 100};
    hb.SetPosition(mouse);
    Enemy e( texture, hb, 0, 100, 1);
    e.addGun(std::make_shared<Gun>(g2));
    npcs.push_back(std::move(e));
}

bool Scene::handleInputs() {
    static float c = 0;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        // for (int i = 0; i < 10; ++i) {
            player->shoot(projectiles, camera->getWorldCursorPos());
            // c += .1;
            // player->shoot(projectiles, player->getPos() + RVector2(100, 100).Rotate(c));
        // }
    }
    // if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
    //     generateEnemy(player, npcs, camera->getWorldCursorPos());
    // }
    if (IsKeyPressed(KEY_R)) {
        auto p = camera->getWorldCursorPos();
        std::cout << p.x << " " << p.y << std::endl;
    }

    return false;
}

std::shared_ptr<Player> Scene::getPlayer() const {
    return player;
}
