@startuml
left to right direction
/'actors'/
"building manager" as bm
"mopping robot" as mopr
"scrubbing robot" as scrubr
"vacuuming robot" as vacuumr

/'check actions'/
"scrub room" as (sr)
"mop room" as (mr)
"vacuum room" as (vr)

/'other actions'/
"next vacuumer available" as (nva)
"next mopper available" as (nma)
"next scrubber available" as (nsa)

bm --> (sr): assign robot to scrub room
bm --> (mr): assign robot to mop room
bm --> (vr): assign robot to vacuum room

(sr) --> scrubr: assign robot to scrub room
(mr) --> mopr: assign robot to mop room
(vr) --> vacuumr: assign robot to vacuum room

(sr) --> (nsa): no scrubbing robots available
(mr) --> (nma): no mopping robots available
(vr) --> (nva): no vacuuming robots available

(nsa) --> bm: time when next scrubbing robot is available
(nma) --> bm: time when next mopping robot is available
(nva) --> bm: time when next vacuuming robot is available
@enduml