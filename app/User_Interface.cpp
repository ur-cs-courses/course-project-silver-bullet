#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>
//#include "RMS.hpp"
#include <memory>
#include "../include/librms/RMS.hpp"
//#include "../include/libroom/room.hpp"
#include <fmt/core.h>
#include <yaml-cpp/yaml.h>

int main() {
    RobotManagementSystem rms;
    std::cout << "Initializing..." << std::endl;
    auto createRobot = [](Size robotSize, Type robotType, int processingTime, std::string loc_value, int xx, int yy) {
        return std::make_unique<Robot>(robotSize, robotType, processingTime, loc_value, xx, yy);
    };
    
    try{
        YAML::Node config = YAML::LoadFile("../../input/config.yaml");

        int robotID = 0; // key value for adding robots to the map in RMS
        int large = 0;
        int small = 0;
        int sweepers = 0;
        int mops = 0;
        int vacuums = 0;
        
        for (int i = 0; i < config["robots"]["large_sweepers"].as<int>(); i++){
            rms.addRobot(robotID, createRobot(Size::Large, Type::Sweeper, 0, "hub", 0, 0));
            robotID++;
            large++;
            sweepers++;
        }

        for (int i = 0; i < config["robots"]["small_sweepers"].as<int>(); i++){
            rms.addRobot(robotID, createRobot(Size::Small, Type::Sweeper, 0, "hub", 0, 0));
            robotID++;
            small++;
            sweepers++;
        }

        for (int i = 0; i < config["robots"]["large_vacuums"].as<int>(); i++){
            rms.addRobot(robotID, createRobot(Size::Large, Type::Vacuum, 0, "hub", 0, 0));
            robotID++;
            large++;
            vacuums++;
        }

        for (int i = 0; i < config["robots"]["small_vacuums"].as<int>(); i++){
            rms.addRobot(robotID, createRobot(Size::Small, Type::Vacuum, 0, "hub", 0, 0));
            robotID++;
            small++;
            vacuums++;
        }

        for (int i = 0; i < config["robots"]["large_mops"].as<int>(); i++){
            rms.addRobot(robotID, createRobot(Size::Large, Type::Mop, 0, "hub", 0, 0));
            robotID++;
            large++;
            mops++;
        }

        for (int i = 0; i < config["robots"]["small_mops"].as<int>(); i++){
            rms.addRobot(robotID, createRobot(Size::Small, Type::Mop, 0, "hub", 0, 0));
            robotID++;
            small++;
            mops++;
        }

    // number of each type of room
        int numLargeRoom = config["rooms"]["large"].size();
        int numMedRoom = config["rooms"]["medium"].size();
        int numSmallRoom = config["rooms"]["small"].size();

        // write number of each rooms to a csv file to be input for the simulation
        std::ofstream csvFile("../../output/room_count.csv");
        csvFile << "large, medium, small" << std::endl;
        csvFile << numLargeRoom << ", " << numMedRoom << ", " << numSmallRoom << std::endl;

        
        // initialize rooms and add to map
        for (int i = 0; i < config["rooms"]["large"].size(); i++){
            std::string name = config["rooms"]["large"][i].as<std::string>();
            rms.addRoom(name, RoomSize::Large);
        }

        for (int i = 0; i < config["rooms"]["medium"].size(); i++){
            std::string name = config["rooms"]["medium"][i].as<std::string>();
            rms.addRoom(name, RoomSize::Medium);
        }

        for (int i = 0; i < config["rooms"]["small"].size(); i++){
            std::string name = config["rooms"]["small"][i].as<std::string>();
            rms.addRoom(name, RoomSize::Small);
        }
    }
    catch(const YAML::BadFile& err){
        std::cerr << "Error: " << err.msg << std::endl;
        fmt::print("Please make sure config.yaml file exists in the input directory and is set up correctly.");
        return 1;
    }
    catch(const YAML::ParserException& err){
        std::cerr << "Error: " << err.msg << std::endl;
        fmt::print("Please make sure config.yaml file is formatted correctly.");
        return 1;
    }
    catch(const YAML::TypedBadConversion<int>& err){
        std::cerr << "Error: " << err.msg << std::endl;
        fmt::print("Please make sure config.yaml file is set up correctly. You may have one or more empty or missing fields.");
        return 1;
    }

    bool flag = true;
    auto timer = std::chrono::high_resolution_clock::now();
    std::string command;
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

                while (!(room_flag) || !(clean_flag))
                {   
                    room_flag = 0;
                    clean_flag = 0;
                    std::cout << "Enter 'mop', 'vacuum', or 'sweeper', or 'cancel' to main menu.\n";
                    std::cin >> choice;
                    if (choice == "cancel"){
                        break;
                    }
                    std::cout << "Enter the location that you would like to clean.\n";
                    std::cin >> room_name;
                    if (choice == "mop" || choice == "vacuum" || choice == "sweeper") {
                        clean_flag = 1;
                    }
                    // Need Modifications
                    if (rms.checkRoom(room_name)){
                        room_flag = 1;
                        rs = rms.getRoomSize(room_name);
                    }
                    if (!(room_flag) || !(clean_flag)){
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
                    int worktime;
                    std::pair<int, int> intPos;
                    if (rs == RoomSize::Small)
                    {
                        worktime = 16;
                        intPos = rms.startPosition(rs, rms.getRoomIndex(room_name));
                        rms.setInitTime(robot_ind, intPos.first, intPos.second);
                    }

                    else if (rs == RoomSize::Medium)
                    {
                        worktime = 49;
                        intPos = rms.startPosition(rs, rms.getRoomIndex(room_name));
                        rms.setInitTime(robot_ind, intPos.first, intPos.second);
                    }

                    else if (rs == RoomSize::Large)
                    {
                        worktime = 100;
                        intPos = rms.startPosition(rs, rms.getRoomIndex(room_name));
                        rms.setInitTime(robot_ind, intPos.first, intPos.second);
                    }
                    
                    rms.add_busyRobot(robot_ind, worktime);
                }
            }

    //         else {
    //             std::cout << "Unknown command. Please enter 'clean', or 'quit' to exit.\n";
    //         }
        }
        
    }
    return 0;
}