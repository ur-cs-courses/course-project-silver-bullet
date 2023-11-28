// #include "RMS.h"
// #include "location.cpp"
//#include "../librobot/robot.h"
#include "../../src/robot.cpp"
#include <unordered_map>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <string>
class RobotManagementSystem {
    private:
        std::unordered_map<int, std::unique_ptr<Robot>> robots;
        // vector<room> loc_info;
        // std::unordered_map<int, std::tuple> robots_position;

    public:
        RobotManagementSystem() {}
        // use for initialization

        // lack of code send to data log
        // use for initialization

        // Algo of Loc & Robot
        
        void addRobot(int index, std::unique_ptr<Robot> r) {
            robots[index] = move(r);
        }

        int requestCleaning(Size robotSize, Type robotType) {
            // check if processtime = 0
            for (auto& info : robots) {
                if (info.second->getTime() == 0){
                    if (robotSize <= info.second->getSize() & robotType == info.second->getType()){
                        return info.first;
                    }
                }
            }
            return -1;
        }

        void debug(){
            for (auto& info : robots) {
                info.second -> print();
            }
        }
};
