#pragma once
#include <raylib-cpp.hpp>
#include "focuses/Focusable.h"


struct Window: public Focusable, public RWindow {
    static Window& instance() {
        static Window window;
        return window;
    }

    void draw() const override {}
    bool handleInputs() override { return false; }
    void update() override {}
    void focus() override {}
    void unfocus() override {}

private:
    Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
};
