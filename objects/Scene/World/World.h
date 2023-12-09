#pragma once

#include "raylib-cpp.hpp"
#include "Room/Room.h"
#include "../../Base/Object.h"


class World {
public:
    World();
    bool collide(const Object& obj) const;
    RRectangle getCollision(const Object& obj) const;
    void draw() const;
    void update();

private:
    void generate();
    void placeRoom(const RVector2& center, unsigned width, unsigned height, std::vector<DoorDirection> doors);
    RVector2 spawnPoint;
    std::vector<Room> rooms;
};
