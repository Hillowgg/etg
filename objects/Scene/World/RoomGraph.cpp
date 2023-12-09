#include "RoomGraph.h"


RoomGraph::RoomGraph(unsigned rooms_num) {
    if (rooms_num == 0) {
        throw std::invalid_argument("rooms_num must be greater than 0");
    }
    rooms.emplace(std::make_pair(0, 0), 1);
    room_positions.push_back({0, 0});
    rooms_num--;

    while (rooms_num > 0) {
        auto room = room_positions[rand() % room_positions.size() / 2 + room_positions.size() / 2];
        auto direction = rand() % 4;
        switch (direction) {
            case 0:
                room.second += 1;
                break;
            case 1:
                room.first += 1;
                break;
            case 2:
                room.second -= 1;
                break;
            case 3:
                room.first -= 1;
                break;
        }
        if (rooms.find(room) == rooms.end()) {
            rooms.emplace(room, 1);
            room_positions.push_back(room);
            rooms_num--;
        }
    }
}

std::map<std::pair<int, int>, int> RoomGraph::getRooms() const {
    return rooms;
}