// roomMain.cpp
#include "../include/libroom/room.hpp"

#include <unordered_map>
#include <iostream>

TEST_CASE("Room Tests"){
    std::unordered_map<std::string, RoomSize> roomDictionary;

    // Create rooms and add them to the dictionary
    Room smallRoom("Bathroom", RoomSize::Small);
    Room mediumRoom("Bedroom", RoomSize::Medium);
    Room largeRoom("Library", RoomSize::Large);

    REQUIRE( smallRoom.getName() == "Bathroom" );
    REQUIRE( smallRoom.getSize() == Small );

    REQUIRE( mediumRoom.getName() == "Bedroom" );
    REQUIRE( mediumRoom.getSize() == Medium );

    REQUIRE( largeRoom.getName() == "Library" );
    REQUIRE( largeRoom.getSize() == Large );

    // roomDictionary[smallRoom.getName()] = smallRoom.getSize();
    // roomDictionary[mediumRoom.getName()] = mediumRoom.getSize();
    // roomDictionary[largeRoom.getName()] = largeRoom.getSize();

    // Display the contents of the dictionary
    // std::cout << "Room Dictionary:\n";
    // for (const auto& entry : roomDictionary) {
    //     std::cout << "Room Name: " << entry.first << ", Size: ";
    //     switch (entry.second) {
    //         case RoomSize::Small:
    //             std::cout << "Small\n";
    //             break;
    //         case RoomSize::Medium:
    //             std::cout << "Medium\n";
    //             break;
    //         case RoomSize::Large:
    //             std::cout << "Large\n";
    //             break;
    //     }
    // }
}
