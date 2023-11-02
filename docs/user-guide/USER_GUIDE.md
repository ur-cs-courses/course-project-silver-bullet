# User Guide

## Input File
In order for the system to manage your robot fleet, we must first know what robots you have, as well as the specifications of your building. Please create a .txt file with all the following information:
```
large_sweepers: int
small_sweepers: int
large_vacuums: int
small_vacuums: int
large_moppers: int
small_moppers: int
large_rooms: [string]
medium_rooms: [string]
small_rooms: [string]
```
Specify the number of robots of each type you have. Specify the names of the rooms in your buildings in their respective lists based on their size - commas between each room and enclosed in brackets.
Please include every item in this list, even if you have none, and follow the exact naming conventions.