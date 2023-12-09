#include "World.h"
#include "../../Base/TextureBase.h"
#include "../../../utils/Textures.h"
#include "RoomGraph.h"
#include "Room/Entity.h"
#include <iostream>
#include <vector>


World::World() {
    generate();
}


void World::generate() {
    rooms.push_back(Room({1500, 500}, 23, 15, {
                             DoorDirection::North, DoorDirection::South, DoorDirection::East, DoorDirection::West
                         }));
    rooms.push_back(Room({1000, -500}, 15, 13, {DoorDirection::South}));
    rooms[0].spawnBoss();
    rooms[1].addChest();
}


void World::draw() const {
    for (const auto&room: rooms) {
        room.draw();
    }
}

void World::update() {
    for (auto&room: rooms) {
        room.update();
    }
    if (IsKeyPressed(KEY_F)) {
        if (rooms[0].isLocked())
            rooms[0].unlock();
        else {
            rooms[0].lock();
        }
    }
}

bool World::collide(const Object& obj) const {
    for (const auto&o: rooms) {
        if (o.collide(obj)) {
            return true;
        }
    }
    return false;
}

RRectangle World::getCollision(const Object& obj) const {
    for (const auto&o: rooms) {
        if (o.collide(obj)) {
            return o.getCollision(obj);
        }
    }
    return RRectangle{0, 0, 0, 0};
}
