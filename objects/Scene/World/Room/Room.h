#pragma once
#include <vector>
#include "../../../Base/Object.h"
#include "Chest.h"

enum DoorDirection {
    North, East, South, West
};


struct Room {
    Room(const RVector2& center, unsigned width, unsigned height, std::vector<DoorDirection> doors);
    void draw() const;
    void update();
    bool collide(const Object& obj) const;
    RRectangle getCollision(const Object& obj) const;
    void lock();
    void unlock();
    bool isLocked() const { return locked; }
    void addChest();
    void spawnBoss();
private:
    std::vector<Object> walls;
    std::vector<Object> floors;
    std::vector<Object> doors;
    std::vector<Object> triggers;
    std::vector<Chest> chests;


    RVector2 center;
    bool locked = false;
    bool boss = false;
    int square_size = 64; // must be even
};
