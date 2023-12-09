#include "Room.h"

#include "../../../../focuses/Scene.h"
#include "../../../../utils/Textures.h"

Room::Room(const RVector2& center, unsigned width, unsigned height, std::vector<DoorDirection> door_sides): center(center) {
    if (width < 5 or height < 5 or width % 2 == 0 or height % 2 == 0) {
        throw std::invalid_argument("Room width and height must be at least 5 and odd");
    }
    auto grasstxt = Textures::getTexture("grass");
    auto walltxt = Textures::getTexture("wall");
    auto doortxt = Textures::getTexture("door");


    int y_offset = square_size * height / 2;
    int x_offset = square_size * width / 2;

    auto check = [this](int x, int center) {
        return x >= center - square_size * 3/2 and x < center + square_size * 3/2;
    };

    auto inDoors = [&door_sides] (DoorDirection dir) {
        return std::find(door_sides.begin(), door_sides.end(), dir) != door_sides.end();
    };

    for (int x = center.x - x_offset; x < center.x + x_offset; x += square_size) {
        if (inDoors(DoorDirection::North) and check(x, center.x)) {
            // floors.emplace_back(grasstxt, RRectangle(x, center.y - y_offset, square_size, square_size));
            doors.emplace_back(doortxt, RRectangle(x, center.y - y_offset, square_size, square_size));
        } else {
            walls.emplace_back(walltxt, RRectangle(x, center.y - y_offset, square_size, square_size));
        }
        if (inDoors(DoorDirection::South) and check(x, center.x)) {
            // floors.emplace_back(grasstxt, RRectangle(x, center.y + y_offset - square_size, square_size, square_size));
            doors.emplace_back(doortxt, RRectangle(x, center.y + y_offset - square_size, square_size, square_size));
        } else {
            walls.emplace_back(walltxt, RRectangle(x, center.y + y_offset - square_size, square_size, square_size));
        }
    }

    for (int y = center.y - y_offset + square_size; y < center.y + y_offset - square_size; y += square_size) {
        if (inDoors(DoorDirection::West) and check(y, center.y)) {
            // floors.emplace_back(grasstxt, RRectangle(center.x - x_offset, y, square_size, square_size));
            doors.emplace_back(doortxt, RRectangle(center.x - x_offset, y, square_size, square_size));
        } else {
            walls.emplace_back(walltxt, RRectangle(center.x - x_offset, y, square_size, square_size));
        }

        if (inDoors(DoorDirection::East) and check(y, center.y)) {
            // floors.emplace_back(grasstxt, RRectangle(center.x + x_offset - square_size, y, square_size, square_size));
            doors.emplace_back(doortxt, RRectangle(center.x + x_offset - square_size, y, square_size, square_size));
        } else {
            walls.emplace_back(walltxt, RRectangle(center.x + x_offset - square_size, y, square_size, square_size));
        }
    }
    for (int x = center.x - x_offset + square_size; x < center.x + x_offset - square_size; x += square_size) {
        for (int y = center.y - y_offset + square_size; y < center.y + y_offset - square_size; y += square_size) {
            floors.emplace_back(grasstxt, RRectangle(x, y, square_size, square_size));
        }
    }
    RVector2 tSize((width - 6) * square_size, (height - 6) * square_size);
    triggers.emplace_back(Textures::getTexture("trigger"), RRectangle(center - tSize / 2, tSize), 0);
}

void Room::update() {
    for (auto& chest: chests) {
        chest.update();
    }
    for (auto& tr: triggers) {
        if (tr.collide(*Scene::instance().getPlayer())) {
            lock();
            // for (int i = 0; i < 10; ++i) {
            //     Scene::instance().spawnEnemy(center);
            // }
            tr.setToDelete(true);
        }
    }

    erase_if(triggers, [](const Object& o) {return o.toDelete();});

    if (Scene::instance().enemyCount() == 0) {
        unlock();
    }
}


void Room::draw() const {
    for (const auto &floor: floors) {
        floor.draw();
    }
    for (const auto &wall: walls) {
        wall.draw();
    }
    for (const auto &door: doors) {
        door.draw();
    }
    for (const auto &trigger: triggers) {
        trigger.draw();
    }
    for (const auto &chest: chests) {
        chest.draw();
    }
}

bool Room::collide(const Object &obj) const {
    for (const auto& chest: chests) {
        if (chest.collide(obj)) {
            return true;
        }
    }
    for (const auto& wall: walls) {
        if (wall.collide(obj)) {
            return true;
        }
    }

    if (locked) {
        for (const auto& door: doors) {
            if (door.collide(obj)) {
                return true;
            }
        }
    }

    return false;
}

RRectangle Room::getCollision(const Object &obj) const {

    for (const auto& wall: walls) {
        if (wall.collide(obj)) {
            return wall.getCollision(obj);
        }
    }

    if (locked) {
        for (const auto& door: doors) {
            if (door.collide(obj)) {
                return door.getCollision(obj);
            }
        }
    }

    return RRectangle{0, 0, 0, 0};
}

void Room::lock() {
    locked = true;
    auto doortxt = Textures::getTexture("door");
    doortxt->setAnim(1);
    if (boss) {
        Scene::instance().spawnBoss(center);
    }
}

void Room::spawnBoss() {
    boss = true;

}


void Room::unlock() {
    locked = false;
    auto doortxt = Textures::getTexture("door");
    doortxt->setAnim(0);
}

void Room::addChest()  {
    auto t = Textures::getTexture("classic_chest");
    chests.emplace_back(t, RRectangle{0, 0, 80, 80}, Entity(Textures::getTexture("shotgun"), RRectangle{center, {100, 50}}));
    chests[0].setPos(center);
}

