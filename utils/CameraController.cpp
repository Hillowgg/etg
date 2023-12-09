#include "CameraController.h"
#include "../Window.h"

CameraController::CameraController(RVector2 looseTarget,
                                   unsigned radius,
                                   float speed): looseTarget(looseTarget), radius(radius), _speed(speed) {
    camera = RCamera2D(Window::instance().GetSize() / 2, looseTarget, 0, 1);
}



void CameraController::begin() {

    updateCameraTargetAsETG();
    camera.BeginMode();
}

void CameraController::updateCameraTargetAsETG() {
    camera.target = looseTarget + (RVector2(GetScreenToWorld2D(RMouse::GetPosition(), camera)) - looseTarget) / 7;
}

void CameraController::updateCameraTarget() {
        if (!inside()) {
        RVector2 diff = looseTarget - camera.target;
        RVector2 move = diff * diff.Length() * speed();
        if(move.Length() > diff.Length()) {
            camera.target = RVector2(camera.target) + diff;
        } else {
            camera.target = RVector2(camera.target) + move;
        }
    }
}

bool CameraController::inside() {
    return CheckCollisionPointCircle(looseTarget, camera.target, radius);
}
