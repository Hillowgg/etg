#pragma once

#include "TextureBase.h"

struct AutoAnimTexture: public TextureBase {

    AutoAnimTexture(const std::string &texturePath, std::vector<RRectangle> inShapes, double delta = 1):
            TextureBase(texturePath, inShapes), delta(delta), lastChange(GetTime()) {};

    AutoAnimTexture(const std::string& texturePath, int verticalTexturesCount = 1, double delta = 1):
            TextureBase(texturePath, verticalTexturesCount), delta(delta) {};


//    void draw(const RRectangle& outShape, const float &rotation = 0) const override = delete;
    void draw(const RRectangle& outShape, const float &rotation = 0) const override;

    void update() override;

private:
    double lastChange;
    double delta;
};
