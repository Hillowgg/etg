#pragma once
#include <map>
#include <raylib-cpp.hpp>



struct RoomGraph {
    RoomGraph(unsigned rooms);
    std::map<std::pair<int, int>, int> getRooms() const;
private:
    std::map<std::pair<int, int>, int> rooms;
    std::vector<std::pair<int, int>> room_positions;
};
