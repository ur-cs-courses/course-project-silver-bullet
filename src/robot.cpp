#include "robot.h"
#include <iostream>
#include <string>

// Constructor
Robot::Robot(Size robotSize, Type robotType, int processingTime, std::string loc_value)
    : size(robotSize), type(robotType), processingTime(processingTime), loc(loc_value) {}

// Getter methods
Size Robot::getSize(){
    return size;
}

Type Robot::getType(){
    return type;
}

int Robot::getTime(){
    return processingTime;
}

// Setter methods
void Robot::setTime(int processingTime) {
    processingTime = processingTime;
}

// Test
void Robot::print(){
    std::cout << static_cast<int>(size) << std::endl;
    std::cout << static_cast<int>(type) << std::endl;
    std::cout << processingTime << std::endl;
    std::cout << loc << std::endl;

}