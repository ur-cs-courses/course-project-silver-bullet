#ifndef RMS_H
#define RMS_H
#include "robot.cpp"
#include <unordered_map>

class RobotManagementSystem {
private:
    std::unordered_map<int, Robot*> robots;

public:
    RobotManagementSystem();
    // use for initialization
    void addRobot(int index, Robot* robot);
    int requestCleaning(Size robotSize, Type robotType);
};
#endif
