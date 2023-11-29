#include <iostream>
#include <string>
#include <memory>
#include "../include/librms/RMS.hpp"
#include "../include/libroom/room.hpp"
#include <fmt/core.h>
#include <yaml-cpp/yaml.h>

int main() {
    // Initialization
    std::cout << "Initializing..." << std::endl;
    RobotManagementSystem rms;
    bool flag = true;
    int timer = 0;
    std::string command;

    std::cout << "Read User Information" << std::endl;
    // Database DB
    // Hard Code DB input

    auto createRobot = [](Size robotSize, Type robotType, int processingTime, std::string loc_value) {
        return std::make_unique<Robot>(robotSize, robotType, processingTime, loc_value);
    };

    // Add robots from config file
    YAML::Node config = YAML::LoadFile("../../input/config.yaml");

    int robotID = 0; // key value for adding robots to the map in RMS

    int large = 0;
    int small = 0;
    int sweepers = 0;
    int mops = 0;
    int vacuums = 0;
    
    for (int i = 0; i < config["robots"]["large_sweepers"].as<int>(); i++){
        rms.addRobot(robotID, createRobot(Size::Large, Type::Sweeper, 0, "hub"));
        robotID++;
        large++;
        sweepers++;
    }

    for (int i = 0; i < config["robots"]["small_sweepers"].as<int>(); i++){
        rms.addRobot(robotID, createRobot(Size::Small, Type::Sweeper, 0, "hub"));
        robotID++;
        small++;
        sweepers++;
    }

    for (int i = 0; i < config["robots"]["large_vacuums"].as<int>(); i++){
        rms.addRobot(robotID, createRobot(Size::Large, Type::Vacuum, 0, "hub"));
        robotID++;
        large++;
        vacuums++;
    }

    for (int i = 0; i < config["robots"]["small_vacuums"].as<int>(); i++){
        rms.addRobot(robotID, createRobot(Size::Small, Type::Vacuum, 0, "hub"));
        robotID++;
        small++;
        vacuums++;
    }

    for (int i = 0; i < config["robots"]["large_mops"].as<int>(); i++){
        rms.addRobot(robotID, createRobot(Size::Large, Type::Mop, 0, "hub"));
        robotID++;
        large++;
        mops++;
    }

    for (int i = 0; i < config["robots"]["small_mops"].as<int>(); i++){
        rms.addRobot(robotID, createRobot(Size::Small, Type::Mop, 0, "hub"));
        robotID++;
        small++;
        mops++;
    }

    fmt::print("There are {} large robots \n", large);
    fmt::print("There are {} small robots \n", small);
    fmt::print("There are {} sweepers \n", sweepers);
    fmt::print("There are {} vacuums \n", vacuums);
    fmt::print("There are {} mops \n", mops);

    // Make a map of building room - ["name": size]
    std::unordered_map<std::string, RoomSize> rooms;

    // number of each type of room
    int numLargeRoom = config["rooms"]["large"].size();
    int numMedRoom = config["rooms"]["medium"].size();
    int numSmallRoom = config["rooms"]["small"].size();

    fmt::print("There are {} large rooms. \n", numLargeRoom);
    fmt::print("There are {} medium rooms. \n", numMedRoom);
    fmt::print("There are {} small rooms. \n", numSmallRoom);
    
    // initialize rooms and add to map
    for (int i = 0; i < config["rooms"]["large"].size(); i++){
        std::string name = config["rooms"]["large"][i].as<std::string>();
        rooms[name] = RoomSize::Large;
    }

    for (int i = 0; i < config["rooms"]["medium"].size(); i++){
        std::string name = config["rooms"]["medium"][i].as<std::string>();
        rooms[name] = RoomSize::Medium;
    }

    for (int i = 0; i < config["rooms"]["small"].size(); i++){
        std::string name = config["rooms"]["small"][i].as<std::string>();
        rooms[name] = RoomSize::Small;
    }

    fmt::print("{} \n","Room Dictionary: ");
    for (const auto& entry : rooms) {
        fmt::print("Room Name: {}, Size: ", entry.first);
        switch (entry.second) {
            case RoomSize::Small:
                fmt::print("{} \n","Small");
                break;
            case RoomSize::Medium:
                fmt::print("{} \n","Medium");
                break;
            case RoomSize::Large:
                fmt::print("{} \n","Large");
                break;
        }
    }

    //rms.debug();
    fmt::print("Welcome to main menu of RMS by Silver Bullet");
    // Main command loop
    // while (flag) {
    //     while (true){
    //         std::cout << "Enter command or enter 'help' for more information: "<< std::endl;
    //         std::cin >> command;

    //         if (command == "quit") {
    //             std::cout << "Exiting the Robot Control System. Goodbye!\n";
    //             flag = false;
    //             break;
    //         }

    //         else if (command == "help"){
    //             std::cout << "Enter 'clean' for cleaning choices, or 'quit' to exit.\n";
    //         }

    //         else if (command == "clean"){
    //             std::string choice;
    //             std::string room_name;
    //             std::cout << "Enter 'mop', 'vacuum', or 'sweeper', or 'cancel' to main menu.\n";
    //             std::cin >> choice;
    //             std::cout << "Enter the location that you would like to clean or 'help' for their names.\n";
    //             std::cin >> room_name;
    //             if (choice == "mop") {
                    
    //             }
                
    //             else if (choice == "vacuum") {
                    
    //             } 
                
    //             else if (choice == "sweeper") {
                    
    //             } 

    //             else{
    //                 std::cout << "Unknown command. Please enter 'mop', 'vacuum', or 'sweeper', or 'cancel' to exit.\n";
    //             }

    //         }

    //         else if (command == " ") {
    //             break;
    //         }

    //         else {
    //             std::cout << "Unknown command. Please enter 'clean', or 'quit' to exit.\n";
    //         }
            
    //     }
    //     timer ++;
    // }
    // Output Datalog
    return 0;
}
