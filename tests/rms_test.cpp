#include <catch2/catch_test_macros.hpp>
#include "../include/librms/RMS.hpp"

TEST_CASE("Robot Management System Tests"){
    RobotManagementSystem rms;

    auto createRobot = [](Size robotSize, Type robotType, int processingTime, std::string loc_value) {
        return std::make_unique<Robot>(robotSize, robotType, processingTime, loc_value);
    };

    //Test addRobot
    SECTION("Adding robots"){
        for (int i = 0; i < 4; i++) {
            rms.addRobot(i, createRobot(Size::Large, Type::Mop, 0, "hub"));
            //rms.addRobot(i, robot1);
        }
        REQUIRE(rms.getNumRobots() == 4);
    }

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
        rms.addRoom("room1", RoomSize::Large);
        rms.addRoom("room2", RoomSize::Medium);
        rms.addRoom("room3", RoomSize::Small);

        REQUIRE(rms.getRoomSize("room1") == RoomSize::Large);
        REQUIRE(rms.getRoomSize("room2") == RoomSize::Medium);
        REQUIRE(rms.getRoomSize("room3") == RoomSize::Small);
    }

    // Test checkFinish method
    SECTION("Check finish"){
        // set initial time to 0 - already finished
        rms.addRobot(0, createRobot(Size::Large, Type::Mop, 0, "hub"));
        REQUIRE(rms.checkFinish(0));

        // set initial time to 9 - not finished
        rms.addRobot(1, createRobot(Size::Small, Type::Sweeper, 9, "hub"));
        REQUIRE_FALSE(rms.checkFinish(1));
    }

    // Test send to location
    SECTION("Send to location"){
        rms.addRobot(0, createRobot(Size::Large, Type::Mop, 0, "hub"));
        rms.sendtoLoc(0, "bathroom");
        REQUIRE(rms.getLocation(0) == "bathroom");
        
        rms.sendtoLoc(0, "hallway");
        REQUIRE_FALSE(rms.getLocation(0) == "bathroom");
    }

    // Test checkRoom
    SECTION("Checking valid room name"){
        rms.addRoom("bathroom", RoomSize::Medium);
        rms.addRoom("bedroom", RoomSize::Small);

        REQUIRE(rms.checkRoom("bathroom"));
        REQUIRE(rms.checkRoom("bedroom"));
        REQUIRE_FALSE(rms.checkRoom("hallway"));
        REQUIRE_FALSE(rms.checkRoom("hub"));
    }

    //Test decrementing Robot cleaning time
    SECTION("Decrementing Robot time"){
        rms.addRobot(0, createRobot(Size::Large, Type::Mop, 20, "hub"));
        rms.dectime(0);
        REQUIRE(rms.getRobotTime(0) == 19);
    }


    //Test add busy robot
    SECTION("Adding a busy robot"){
        rms.addRobot(0, createRobot(Size::Large, Type::Mop, 0, "hub"));
        rms.addRobot(1, createRobot(Size::Small, Type::Vacuum, 0, "hub"));

        rms.add_busyRobot(0, 20);
        rms.add_busyRobot(1, 15);

        REQUIRE(rms.getNumBusy() == 2);
        REQUIRE(rms.getRobotTime(0) == 20);
        REQUIRE(rms.getRobotTime(1) == 15);
    }
}