#include <iostream>
#include "App.h"

int main() {
    try {
        App::instance().run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

