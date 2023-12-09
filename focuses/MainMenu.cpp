#include "MainMenu.h"

#include <utility>
#include "../App.h"
#include "../Window.h"

bool MainMenu::handleInputs() {
    if (IsKeyDown(KEY_UP)) {
        icon.width = icon.height *= 1.01;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        icon.width = icon.height *= 0.99;
    }
    return false;
}

void MainMenu::focus() {

}

void MainMenu::unfocus() {

}

void MainMenu::draw() const {
    startButton->draw();
}

MainMenu::MainMenu(std::shared_ptr<bool> start): start(start) {
    float newHeight = Window::instance().GetHeight() / 10;
    float coef = icon.height / newHeight;

    icon.height = newHeight;
    icon.width /= coef;

    std::string base = "/Users/hillow/CLionProjects/raylib_trying/textures/";
    std::string start_path = base + "start_button/start.png";

    auto texture = std::make_shared<TextureBase>(start_path, 3);
    startButton = std::make_unique<Button>(texture, RRectangle {0, 0, 256, 128});
    startButton->setOnClick([]() {App::instance().startGame();});
    startButton->setPos(Window::instance().GetSize() / 2);
}

void MainMenu::update() {
    startButton->update();
    handleInputs();
}

