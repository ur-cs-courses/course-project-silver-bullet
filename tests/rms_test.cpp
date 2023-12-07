#include <catch2/catch_test_macros.hpp>
#include "../include/librms/RMS.hpp"

TEST_CASE("Robot Management System Tests"){
    RobotManagementSystem rms;

    auto createRobot = [](Size robotSize, Type robotType, int processingTime, std::string loc_value) {
        return std::make_unique<Robot>(robotSize, robotType, processingTime, loc_value);
    };
    
    std::unique_ptr<Robot> robot1 = std::make_unique<Robot>(Size::Large, Type::Mop, 0, "hub");

    Room room1{"hub", RoomSize::Large};

    //Test addRobot
    SECTION("Adding robots"){
        for (int i = 0; i < 4; i++) {
            rms.addRobot(i, createRobot(Size::Large, Type::Mop, 0, "hub"));
            //rms.addRobot(i, robot1);
        }
        REQUIRE(rms.getNumRobots() == 4);
    }

    //Test send to location

    //Test decrementing Robot cleaning time

    //Test addRoom
    SECTION("Adding rooms"){
        for (int i = 0; i < 2; i++){
            rms.addRoom("room" + std::to_string(i), RoomSize::Large);
        }
        for (int i = 2; i < 5; i++){
            rms.addRoom("room" + std::to_string(i), RoomSize::Medium);
        }
        for (int i = 5; i < 9; i++){
            rms.addRoom("room" + std::to_string(i), RoomSize::Small);
        }

        REQUIRE(rms.getNumRooms() == 9);
    }

    //Test getting Room size based on name
    SECTION("Get room size"){
        for (int i = 0; i < 2; i++){
            rms.addRoom("room" + std::to_string(i), RoomSize::Large);
        }
        for (int i = 2; i < 5; i++){
            rms.addRoom("room" + std::to_string(i), RoomSize::Medium);
        }
        for (int i = 5; i < 9; i++){
            rms.addRoom("room" + std::to_string(i), RoomSize::Small);
        }

        REQUIRE(rms.getRoomSize("room1") == RoomSize::Large);
        REQUIRE(rms.getRoomSize("room4") == RoomSize::Medium);
        REQUIRE(rms.getRoomSize("room7") == RoomSize::Small);
    }

}