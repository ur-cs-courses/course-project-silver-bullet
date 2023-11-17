// roomMain.cpp

#include <iostream>
#include "room.h"

int main() {
    std::vector<Room> rooms; // Vector to store multiple Room objects
    char userChoice; // Variable to store user input for continuing or exiting the loop

    do {
        // Variables to store user input for each room
        std::string userRoomName;
        int userRoomSize;

        // Get user input for room name
        std::cout << "Enter the room name (or 'x' to exit): ";
        std::getline(std::cin, userRoomName);

        // Check if the user wants to exit
        if (userRoomName == "x") {
            break; // Exit the loop
        }

        // Get user input for room size
        std::cout << "Enter the room size (1 for Small, 2 for Medium, 3 for Large): ";
        std::cin >> userRoomSize;
        std::cin.ignore(); // Clear the input buffer

        // Create a Room object with user input and add it to the vector
        rooms.push_back(Room(userRoomName, userRoomSize));

        // Ask the user if they want to enter another room
        std::cout << "Do you want to enter another room? (Enter 'x' to exit, any other key to continue): ";
        std::cin >> userChoice;
        std::cin.ignore(); // Clear the input buffer

    } while (userChoice != 'x');

    // Display information about all the rooms entered by the user
    std::cout << "\nDetails of all entered rooms:" << std::endl;
    for (const auto& room : rooms) {
        room.displayInfo();
    }

    return 0;
}
