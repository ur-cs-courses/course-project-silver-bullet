// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>

class Room {
private:
    std::string name;
    int size;

public:
    Room(const std::string& roomName, int roomSize);

    std::string getName() const;
    void setName(const std::string& newName);

    int getSize() const;
    void setSize(int newSize);

    void displayInfo() const;
};

#endif // ROOM_H