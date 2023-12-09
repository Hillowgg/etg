#pragma once

#include "../Base/Object.h"
#include <iostream>


template<typename T>
class StatusBar: public Object {
public:
    StatusBar(std::shared_ptr<TextureBase> barTexture,
              RRectangle hitBox,
              std::function<T()> getValue,
              std::function<T()> getMaxValue,
              RColor color): Object(barTexture, hitBox), getValue{getValue}, getMaxValue(getMaxValue), color(color) {}

    void draw() const override {
        auto hb = hitBox;
        hb.SetWidth(hb.GetWidth() * (static_cast<float>(getValue()) / getMaxValue()));
        texture->drawByIdWithFilter(1, hb, color, 0);
        texture->drawById(0,hitBox, 0);
    }

private:
    std::function<T()> getMaxValue;
    std::function<T()> getValue;
    RColor color;
};
