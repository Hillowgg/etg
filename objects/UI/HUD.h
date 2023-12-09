#pragma once
#include "StatusBar.h"


class HUD {
public:
    explicit HUD();
    void draw();
private:
    std::unique_ptr<StatusBar<int>> healthBar;
    std::unique_ptr<StatusBar<int>> ammoBar;
    // std::unique_ptr<StatusBar> xpBar;
};
