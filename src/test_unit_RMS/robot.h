#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

// Enum for Robot Size
enum class Size {
    Small,
    Medium,
    Large
};

// Enum for Robot Type
enum class Type {
    Sweeper,
    Vacuum,
    Mop
};

class Robot {
private:
    Size size;
    Type type;
    int processingTime;
    std::string loc;

public:
    // Constructor
    Robot(Size robotSize, Type robotType, int processingTime, std::string loc);

    // Getter methods
    Size getSize();
    Type getType();
    int getTime();

    // Setter methods
    void setTime(int processingTime);

    // Test Meth
    void print();
    
};

#endif // ROBOT_H
