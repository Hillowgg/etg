#define DEBUG
#include <iostream>
#include <thread>
#include "App.h"
#include "Window.h"
#include "utils/Textures.h"

void App::run() {
    initApp();
    initLoop();
}


//todo: make real loading
void App::loadConfig() {
    Textures::loadTextures();
}

void App::handleInputs() {

    bool block = menu->handleInputs();

    if (block) return;

    // if (IsKeyPressed(controls[ACTION_OC_MENU])) {
    //     focus = menu;
    //     focus->focus();
    // }

    if (IsKeyPressed(controls[ACTION_OC_INVENTORY])) {
    }
    if (IsKeyPressed(controls[ACTION_FULLSCREEN])) { window->ToggleFullscreen(); }
}

void App::initApp() {
    int monitor = GetCurrentMonitor();

    Window::instance();
    loadConfig();
    mouseTexture = RTexture2D("/Users/hillow/CLionProjects/raylib_trying/textures/cursor.png");
    mouseTextureSize = RVector2(mouseTexture.GetSize()) * .2;

    // scene = std::make_shared<Scene>();
    menu = std::make_shared<MainMenu>(start);
    // focus = menu;
}



void App::initLoop() {
    SetExitKey(0);
    DisableCursor();

    while (!window->ShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        if (focus == CurFocus::SCENE) {
            Scene::instance().update();
            Scene::instance().draw();
        } else {
            menu->update();
            menu->draw();
        }

#ifdef DEBUG
        DrawText(std::to_string(window->GetFPS()).c_str(), 0, 0, window->GetHeight() / 30, GREEN);
#endif
        mouseTexture.Draw(mouse.GetPosition() - mouseTextureSize / 2, 0, .2);
        EndDrawing();
    }
}
