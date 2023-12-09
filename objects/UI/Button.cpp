#include <utility>
#include "Button.h"


void Button::update() {
    bool collision = this->collide(static_cast<RVector2>(GetMousePosition()));
    if (!wasDown) {
        wasDown = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
    }

    if (collision) {
        state = ButtonState::Hover;
        if (wasDown) {
            state = ButtonState::Click;
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                onClick();
                wasDown = false;
            }
        }
    } else {
        state = ButtonState::Default;
    }
}

void Button::draw() const {
    texture->setAnim(state);
    Object::draw();
}

