#pragma once
#include "../objects/Base/TextureBase.h"
#include <map>

// write a class that will load all textures and store them in a map
// class Textures {
//
// public:
//
//
// };

struct Textures {
    static Textures& Instance();
    static void loadTextures();
    static std::shared_ptr<TextureBase> getTexture(const std::string& textureName);

    Textures(const Textures&) = delete;
    Textures& operator=(const Textures&) = delete;
private:
    std::map<std::string, std::shared_ptr<TextureBase>> textures;
    Textures()= default;
};

// namespace Textures {
//
//
//
// }
