// room.cpp

#include "room.h"

Room::Room(const std::string& roomName, int roomSize) : name(roomName), size(roomSize) {}

std::string Room::getName() const {
    return name;
}

void Room::setName(const std::string& newName) {
    name = newName;
}

int Room::getSize() const {
    return size;
}

void Room::setSize(int newSize) {
    size = newSize;
}

void Room::displayInfo() const {
    std::string sizeStr;

    switch (size) {
        case 1:
            sizeStr = "Small";
            break;
        case 2:
            sizeStr = "Medium";
            break;
        case 3:
            sizeStr = "Large";
            break;
        default:
            sizeStr = "Unknown";
            break;
    }

    std::cout << "Room Name: " << name << ", Size: " << sizeStr << std::endl;
}
