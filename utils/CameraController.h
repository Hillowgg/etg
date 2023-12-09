#pragma once
#include <raylib-cpp.hpp>

class CameraController {
public:
    CameraController(RVector2 looseTarget, unsigned radius, float speed);


    void setTarget(RVector2 vec) {looseTarget = vec;}
    RVector2 getWorldPos(RVector2 vec) const { return GetScreenToWorld2D(vec, camera);}
    RVector2 getWorldCursorPos() const {return getWorldPos(GetMousePosition());}
    void begin();
    void end() {camera.EndMode();/*DrawCircleV(camera.offset,radius, {100, 0, 0, 100});*/}

private:
    bool inside();
    float speed() {return _speed * GetFrameTime();};
    void updateCameraTargetAsETG();
    void updateCameraTarget();

    float radius;
    float const _speed;
    RCamera2D camera;
    RVector2 looseTarget;
};
