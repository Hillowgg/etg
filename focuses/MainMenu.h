#pragma once

#include "Focusable.h"
#include "../objects/UI/Button.h"
#include "raylib-cpp.hpp"


class MainMenu : public Focusable {
public:
    explicit MainMenu(std::shared_ptr<bool>);
    bool handleInputs(/* need to handle inputs here*/) override;

    void focus() override;

    void unfocus() override;

    void draw() const override;
    void update() override;

private:
    RColor backGroundColor{27, 19, 21};
    std::shared_ptr<bool> start;
    RTexture2D icon;
    std::unique_ptr<Button> startButton;
    std::unique_ptr<Button> optButton;
    bool firstDraw = false;
    float animation = 0;
};
