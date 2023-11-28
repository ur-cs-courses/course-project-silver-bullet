#include <iostream>
#include <string>
#include <memory>
#include "RMS.hpp"

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

    // Example of adding robots (hard code)
    for (int i = 1; i <= 5; ++i) {
        // YAML e.g give robotsize a value
        rms.addRobot(i, createRobot(Size::Small, Type::Mop, 0, "hub"));
    }

    rms.debug();
    std::cout << "Welcome to main menu of RMS by Silver Bullet" << std::endl;
    // Main command loop
    while (flag) {
        while (true){
            std::cout << "Enter command or enter 'help' for more information: "<< std::endl;
            std::cin >> command;

            if (command == "quit") {
                std::cout << "Exiting the Robot Control System. Goodbye!\n";
                flag = false;
                break;
            }

            else if (command == "help"){
                std::cout << "Enter 'clean' for cleaning choices, or 'quit' to exit.\n";
            }

            else if (command == "clean"){
                std::string choice;
                std::string room_name;
                std::cout << "Enter 'mop', 'vacuum', or 'sweeper', or 'cancel' to main menu.\n";
                std::cin >> choice;
                std::cout << "Enter the location that you would like to clean or 'help' for their names.\n";
                std::cin >> room_name;
                if (choice == "mop") {
                    
                }
                
                else if (choice == "vacuum") {
                    
                } 
                
                else if (choice == "sweeper") {
                    
                } 

                else{
                    std::cout << "Unknown command. Please enter 'mop', 'vacuum', or 'sweeper', or 'cancel' to exit.\n";
                }

            }

            else if (command == " ") {
                break;
            }

            else {
                std::cout << "Unknown command. Please enter 'clean', or 'quit' to exit.\n";
            }
            
        }
        timer ++;
    }
    // Output Datalog
    return 0;
}
