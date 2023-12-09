#include "Textures.h"
#include "../objects/Base/AutoAnimTexture.h"

#include <iostream>


Textures& Textures::Instance() {
    static Textures instance;
    return instance;
}

void Textures::loadTextures() {
    auto&textures = Textures::Instance().textures;
    textures.emplace("player", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/player/txt.png",
                         4));

    textures.emplace("wall", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/world/wall.png",
                         1));

    textures.emplace("cursor", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/cursor.png",
                         1));

    textures.emplace("enemy", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/player/txt.png",
                         4));

    textures.emplace("shotgun", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/guns/shotgun.png",
                         1));

    textures.emplace("pistol_gun", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/guns/pistol.png",
                         1));
    textures.emplace("sniper_gun", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/guns/sniper.png",
                         1));
    textures.emplace("rifle_gun", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/guns/rifle.png",
                         1));

    constexpr float xoffset = 304;
    constexpr float yoffset = 16 * 7;
    textures.emplace("fireball", std::make_shared<AutoAnimTexture>(AutoAnimTexture(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/projectiles/Fire.png",
                         {
                             RRectangle{xoffset, yoffset, 16, 16},
                             RRectangle{xoffset + 16, yoffset, 16, 16},
                             RRectangle{xoffset + 32, yoffset, 16, 16},
                             RRectangle{xoffset + 48, yoffset, 16, 16}
                         },
                         .01)));

    constexpr float pistolXOffset = 304;
    constexpr float pistolYOffset = 16 * 9;
    textures.emplace("pistol_bullet", std::make_shared<AutoAnimTexture>(AutoAnimTexture(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/projectiles/Water.png",
                         {
                             RRectangle{pistolXOffset, pistolYOffset, 16, 16},
                             RRectangle{pistolXOffset + 16, pistolYOffset, 16, 16},
                             RRectangle{pistolXOffset + 32, pistolYOffset, 16, 16},
                             RRectangle{pistolXOffset + 48, pistolYOffset, 16, 16}
                         },
                         .03)));
    constexpr float sniperXOffset = 15 * 16;
    constexpr float sniperYOffset = 16 * 10;
    textures.emplace("sniper_bullet", std::make_shared<AutoAnimTexture>(AutoAnimTexture(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/projectiles/Purple.png",
                         {
                             RRectangle{sniperXOffset, sniperYOffset, 16, 16},
                             RRectangle{sniperXOffset + 16, sniperYOffset, 16, 16},
                             RRectangle{sniperXOffset + 32, sniperYOffset, 16, 16},
                             RRectangle{sniperXOffset + 48, sniperYOffset, 16, 16}
                         },
                         .05)));
    constexpr float shotgunXOffset = 16 * 12;
    constexpr float shotgunYOffset = 16 * 9;

    textures.emplace("shotgun_bullet", std::make_shared<TextureBase>(
                         TextureBase("/Users/hillow/CLionProjects/raylib_trying/textures/projectiles/Fire.png",
                                     RRectangle{shotgunXOffset, shotgunYOffset, 16, 16}
                         )));

    textures.emplace("grass", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/world/grass.png",
                         1));

    textures.emplace("door", std::make_shared<TextureBase>(
                         TextureBase(
                             "/Users/hillow/CLionProjects/raylib_trying/textures/world/walls.png",
                             {RRectangle{6 * 16, 10 * 16, 16, 16}, RRectangle{16 * 2, 16 * 4, 16, 16}})
                     ));
    textures.emplace("trigger", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/world/walls.png",
                         RRectangle{6 * 16, 3 * 16, 16, 16}));


    textures.emplace("fire_sprite", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/projectiles/Fire.png",
                         1));

    textures.emplace("classic_chest", std::make_shared<TextureBase>(
                         TextureBase(
                             "/Users/hillow/CLionProjects/raylib_trying/textures/world/chests.png",
                             {
                                 RRectangle{4 * 32, 5 * 32, 32, 32},
                                 RRectangle{4 * 32, 7 * 32, 32, 32}
                             })));
    textures.emplace("status_bar", std::make_shared<TextureBase>(
                         "/Users/hillow/CLionProjects/raylib_trying/textures/status_bar.png",
                         2));
    std::cout << "Textures loaded: " << textures.size() << std::endl;
}

std::shared_ptr<TextureBase> Textures::getTexture(const std::string&textureName) {
    auto&textures = Textures::Instance().textures;
    return textures.at(textureName);
}
