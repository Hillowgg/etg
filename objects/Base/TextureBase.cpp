#include "TextureBase.h"


TextureBase::TextureBase(const std::string &texturePath, int verticalTexturesCount) : texture(
        std::make_shared<RTexture2D>(texturePath)) {

    if (texture->GetHeight() % verticalTexturesCount != 0) {
        throw std::range_error("Wrong number of textures or wrong shape of texture");
    }

    int height = texture->GetHeight() / verticalTexturesCount;

    for (int i = 0; i < verticalTexturesCount; i++) {
        inShapes.emplace_back(0, height * i, texture->GetWidth(), height);
    }

};

void TextureBase::draw(const RRectangle &outShape, const float &rotation) const {
    auto t = inShapes[anim];
    texture->Draw(t, outShape, {0, 0}, rotation, {255, 255, 255, transparency});
};

void TextureBase::drawWithFilter(const RRectangle &outShape, const Color &color, const float &rotation) const {
    auto t = inShapes[anim];
    texture->Draw(t, outShape, {0, 0}, rotation, color);
}

void TextureBase::drawById(unsigned int id, const RRectangle &outShape, const float &rotation) const {
    auto t = inShapes[id];

    texture->Draw(t, outShape, {0, 0}, rotation);
}
void TextureBase::drawByIdWithFilter(unsigned int id, const RRectangle &outShape, const Color &color, const float &rotation) const {
    auto t = inShapes[id];
    texture->Draw(t, outShape, {0, 0}, rotation, color);
}

void TextureBase::animNext() { ++anim %= inShapes.size(); }

void TextureBase::setAnim(uint8_t anim_) { anim = anim_; }

void TextureBase::setTransparency(unsigned char transparency_) { transparency = transparency_; }