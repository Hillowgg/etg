#include "raylib-cpp.hpp"
#include <iostream>

#define DEBUG


void UpdateDrawFrame(raylib::Window& window) {
    BeginDrawing();

    ClearBackground(GRAY);
#ifdef DEBUG
    DrawText(std::to_string(window.GetFPS()).c_str(), 0, 0, window.GetHeight() / 30, GREEN);
#endif
    EndDrawing();
}



int main() {
    int curMonitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(curMonitor);
    int monitorHeight = GetMonitorHeight(curMonitor);

    raylib::Window window(
            monitorWidth,
            monitorWidth,
            "My raylib",
            FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT
    );

    return 0;
}

