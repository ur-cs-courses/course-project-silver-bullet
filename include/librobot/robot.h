#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

// Enum for Robot Size
enum class Size {
    Small,
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
    Robot();

    // Virtual methods
    virtual int clean();
    virtual ~Robot() = default;

    // Getter methods
    Size getSize();
    Type getType();
    int getTime();

    // Setter methods
    void setTime(int processingTime);
    void setSize(std::string input_size);
    void setType(std::string input_type);
    void setLoc(std::string input_loc);

    // Test Meth
    void print();
};

class Mop: public Robot {
    public:
        Mop(Size robotSize, Type robotType, int processingTime, std::string loc_value);
        int clean() override;
};

class Vacuum: public Robot {
    public:
        Vacuum(Size robotSize, Type robotType, int processingTime, std::string loc_value);
        int clean() override;
};

class Sweeper: public Robot {
    public:
        Sweeper(Size robotSize, Type robotType, int processingTime, std::string loc_value);
        int clean() override;
};

#endif // ROBOT_H
