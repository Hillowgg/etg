#pragma once
#include <iostream>
#include <raylib-cpp.hpp>
#include "focuses/Focusable.h"
#include "focuses/MainMenu.h"
#include "focuses/Scene.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH  800
#define WINDOW_TITLE  "Fire calamity"

#define ACTION_MOVE_UP    0x0001
#define ACTION_MOVE_DOWN  0x0002
#define ACTION_MOVE_LEFT  0x0003
#define ACTION_MOVE_RIGHT 0x0004

#define ACTION_OC_INVENTORY 0x0010
#define ACTION_OC_MENU      0x0020
#define ACTION_FULLSCREEN   0x0030

enum CurFocus {
    MENU,
    SCENE
};

struct App {

    static App& instance() {
        static App app;
        return app;
    }

    void run();
    void initApp();

    void initLoop();
    void loadConfig();
    void handleInputs();

    void openMenu() {
        focus = MENU;
    }
    void startGame() {
        focus = SCENE;
    }

    void overGame() {
        Scene::instance().reset();
    }

private:
    App() = default;
    App(const App&) = delete;
    App& operator=(const App&) = delete;

    std::shared_ptr<bool> start = std::make_shared<bool>(false);
    std::shared_ptr<RWindow> window;
    raylib::Mouse mouse;
    RTexture2D mouseTexture;
    RVector2 mouseTextureSize;
    CurFocus focus;
    std::shared_ptr<MainMenu> menu;
    // todo: make enum of actions
    std::unordered_map<int,int> controls; // map of action -> key
};
