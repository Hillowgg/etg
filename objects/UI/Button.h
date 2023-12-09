#pragma once

#include "../Base/Object.h"
#include "raylib-cpp.hpp"

enum ButtonState {
    Default, Hover, Click
};

struct Button : public Object {
    Button(std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rotation = 0) : Object(texture, hitBox,
                                                                                                 rotation) {}

    Button(std::function<void()> onClick_, std::shared_ptr<TextureBase> texture, RRectangle hitBox, float rotation = 0)
            : Object(texture, hitBox, rotation), onClick(onClick_) {}

    void draw() const override;

    void update() override;

    void setOnClick(std::function<void()> onClick_) { onClick = onClick_; }


private:
    bool wasDown;
    ButtonState state;
    std::function<void()> onClick;
};
