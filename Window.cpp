#include "Window.h"


Window::Window(): RWindow(1400, 900, "Hello", FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT) {
}
