//
// Created by s3rius on 22.04.19.
//



#pragma once


#include "position.h"
#include "door.h"
typedef struct Room {
    Position position;
    int height;
    int width;
    int numberOfDoors;
    struct Door **doors;
    // Monster ** monsters;
    // Item ** items;
} Room;
