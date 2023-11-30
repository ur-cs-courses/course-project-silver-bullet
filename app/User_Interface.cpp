#include <iostream>
#include <string>
#include <memory>
#include <random>
#include <thread>
#include <chrono>
#include "RMS.hpp"

int main() {
    RobotManagementSystem rms;
    // Initialization Starts HERE !!!
    bool flag = true;
    auto timer = std::chrono::high_resolution_clock::now();
    std::string command;
    //-------------------------------------------------------------------------------------------
    auto createRobot = [](Size robotSize, Type robotType, int processingTime, std::string loc_value) {
        return std::make_unique<Robot>(robotSize, robotType, processingTime, loc_value);
    };

    // Example of adding robots (hard code)
    rms.addRobot(1, createRobot(Size::Small, Type::Mop, 0, "hub"));
    rms.addRobot(2, createRobot(Size::Large, Type::Mop, 0, "hub"));
    rms.addRobot(3, createRobot(Size::Small, Type::Vacuum, 0, "hub"));

    rms.addRoom("R1", RoomSize::Large);
    rms.addRoom("R2", RoomSize::Small);
    rms.addRoom("R3", RoomSize::Medium);

    // rms.debug();

    //-------------------------------------------------------------------------------------------
    while (flag)
    {   
        // Separate a thread for simulation
        // std::thread th1(&RobotManagementSystem::helloworld, &rms);
        std::thread th1(&RobotManagementSystem::simulation, &rms);
        while (true){
            std::cout << "Enter command or enter 'help' for more information: "<< std::endl;
            std::cin >> command;

            if (command == "quit") {
                std::cout << "Exiting the Robot Control System. Goodbye!\n";
                rms.setmtxlock(true);
                th1.join();
                flag = false;
                break;
            }

            else if (command == "help"){
                std::cout << "Enter 'clean' for cleaning choices, or 'quit' to exit.\n";
            }

            else if (command == "clean"){
                int room_flag = 0;
                int clean_flag = 0;
                int robot_ind = -1;
                std::string choice;
                std::string room_name;
                RoomSize rs;

                while (!(room_flag || clean_flag))
                {   
                    room_flag = 0;
                    clean_flag = 0;
                    std::cout << "Enter 'mop', 'vacuum', or 'sweeper', or 'cancel' to main menu.\n";
                    std::cin >> choice;
                    if (choice == "cancel"){
                        break;
                    }
                    std::cout << "Enter the location that you would like to clean or 'help' for their names.\n";
                    std::cin >> room_name;
                    if (choice == "mop" || choice == "vacuum" || choice == "sweeper") {
                        clean_flag = 1;
                    }
                    // Need Modifications
                    if (rms.checkRoom(room_name)){
                        room_flag = 1;
                        rs = rms.getRoomSize(room_name);
                    }
                    if (!(room_flag || clean_flag)){
                        std::cout << "Please enter correct cleaning type or room name.\n";
                    }
                }
                
                if (choice == "mop") {
                    int t = rms.requestCleaning(rs, Type::Mop);
                    if (t != -1){
                        robot_ind = t;
                        rms.sendtoLoc(robot_ind, room_name);
                    }
                }
                
                else if (choice == "vacuum") {
                    int t = rms.requestCleaning(rs, Type::Vacuum);
                    if (t != -1){
                        robot_ind = t;
                        rms.sendtoLoc(robot_ind, room_name);
                    }
                } 
                
                else if (choice == "sweeper") {
                    int t = rms.requestCleaning(rs, Type::Sweeper);
                    if (t != -1){
                        robot_ind = t;
                        rms.sendtoLoc(robot_ind, room_name);
                    }
                } 

                if (robot_ind == -1){
                    if (room_flag){
                        std::cout << "No Robot Available Right Now.\n";
                    }
                    else{
                        std::cout << "Unknown Command.\n";
                    }
                }

                else{
                    // worktime here will be changed
                    int worktime = 10;
                    rms.add_busyRobot(robot_ind, worktime);
                }
            }

            else {
                std::cout << "Unknown command. Please enter 'clean', or 'quit' to exit.\n";
            }
            
        }
        
    }

    return 0;
}