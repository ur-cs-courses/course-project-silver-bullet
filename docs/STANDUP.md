# Standup Documentation

This file contains each team member's individual contributions for our biweekly standup meetings.

## Standup 2: November 2, 2023

Jenna: 
+ Created design for input file to our system
    + Added this documentation to the USER_GUIDE.md
+ Began working on the code that will process the input file
+ Created this file for standup documentation

Yili:
+ Modify and specify the overall class diagram
    + Reduce coupling
+ Began working on several pseudo code
    + Room
    + RMS
    + UI
+ If possible having working units for classes mentioned above

Thando:
+ Designed a detailed sequence diagram to show how the datalog is updated based on the occurance of important events like:
    + success and failure of robots
    + Requests from the BM
    + When robot finishes its task

Tony: 
+ come up with a mouse clicking simulation of robot cleanning
+ Add more Robot's attributes in Robot class digram
+ Write Code to similuate the probability of robot failure

## Standup 3: November 16, 2023

Jenna:
+ Continued to work on linking the yaml-cpp library
    + Still getting the 'file not found' error, even when linking running CMake
+ Brainstorming alternate input ideas but planning to go to office hours for help

Thando:
+ Created the first version of the room class
    + This was seperated into header, cpp and main files but I might have to remove the header file.
    + This version allows the user to input the rooms and sizes manually instead of using the yaml files
    + This version does not take room dimenstions. It takes small, medium, and large as room size.

