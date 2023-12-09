#include "HUD.h"
#include "../../utils/Textures.h"
#include "../../focuses/Scene.h"

HUD::HUD() {
    const RColor healthColor = {255, 77 ,77, 255};
    const RColor ammoColor = {52, 235, 110, 255};
    // RColor xpColor = {66, 135 ,245, 255};

    const auto barTexture = Textures::Instance().getTexture("status_bar");
    const auto getHP = []() -> int {return Scene::instance().getPlayer()->getHp();};
    const auto getMaxHP = []() -> int {return Scene::instance().getPlayer()->getMaxHp();};
    const auto getAmmo = []() -> int {return Scene::instance().getPlayer()->getGun()->getAmmo();};
    const auto getMaxAmmo = []() -> int {return Scene::instance().getPlayer()->getGun()->getMaxAmmo();};

    healthBar = std::make_unique<StatusBar<int>>(
        StatusBar<int>(barTexture,{0, 0, 380, 100}, getHP, getMaxHP, healthColor)
        );

    ammoBar = std::make_unique<StatusBar<int>>(
        StatusBar<int>(barTexture,{0, 100, 380, 100}, getAmmo, getMaxAmmo, ammoColor)
        );

}


void HUD::draw() {
    healthBar->draw();
    ammoBar->draw();
}