# User Guide

### Welcome to **Silver Bullet's Cleaning Robot Management System!** We thank you for choosing our service.

Getting started with our system is quite easy, just follow the steps below and you'll be able to manage your fleet with ease in no time!

## Clone the Repo

First step is to clone this repository to your local machine.  
`$ git clone https://github.com/ur-cs-courses/course-project-silver-bullet.git `

## Config File Setup
In order for the system to manage your robot fleet, we must first know what robots you have, as well as the specifications of your building. Please make sure the `config.YAML` file in the `input` directory is updated accurately with all the following information:
```
robots:
    large_sweepers: int
    small_sweepers: int
    large_vacuums: int
    small_vacuums: int
    large_moppers: int
    small_moppers: int
rooms:
    large: ["room_name", ...]
    medium: ["room_name", ...]
    small: ["room_name", ...]
```
Specify the number of robots of each type you have. Specify the names of the rooms in your buildings in their respective lists based on their size.
The file is already populated with example values for your reference.

## Running the Program

Once you've set up the configuration file to your specifications, you're ready to run the program! 

A minimum of CMake Version 3.16 is required for our program.

The `app` directory houses our top-level program `User_Interface.cpp`. Using CMake, build and run the `user_interface` executable to run the program! Further instructions will prompt you on the command line.

## Outputs

After completion of the program, you can access the `robot_log.txt` in the `output` directory which will show you a data log of all your interactions with the program, including the assignment and completion of tasks, and when a robot breaks and gets fixed.