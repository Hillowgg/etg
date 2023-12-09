#pragma once

#include "raylib-cpp.hpp"
#include <utility>

struct TextureBase {
    TextureBase() = default;
    TextureBase(const std::string &texturePath, std::vector<RRectangle> inShapes) :
    texture(std::make_shared<RTexture2D>(texturePath)),
    inShapes(std::move(inShapes)) {
    }

    TextureBase(const std::string &texturePath, RRectangle inShape):
    texture(std::make_shared<RTexture2D>(texturePath)),
    inShapes(std::vector<RRectangle>({inShape})) {}

    TextureBase(const std::string& texturePath, int verticalTexturesCount = 1);


    virtual void draw(const RRectangle& outShape, const float &rotation = 0) const;
    virtual void drawWithFilter(const RRectangle& outShape, const Color& color, const float &rotation = 0) const;
    virtual void drawById(unsigned id, const RRectangle& outShape, const float &rotation = 0) const;
    virtual void drawByIdWithFilter(unsigned id, const RRectangle& outShape, const Color& color, const float &rotation = 0) const;
    virtual void update() {};

    void setTransparency(unsigned char transparency);

    void animNext();

    void setAnim(uint8_t anim_);

protected:
    std::shared_ptr<RTexture2D> texture;
    std::vector<RRectangle> inShapes;
    uint8_t anim = 0;
    unsigned char transparency = 255;
};