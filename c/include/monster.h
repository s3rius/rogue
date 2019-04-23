//
// Created by s3rius on 22.04.19.
//



#pragma once

#include "position.h"
#include "player.h"
#include "room.h"

typedef struct Monster {
    char str[2];
    char tile;
    int health;
    int attack;
    int speed;
    int defence;
    int alive;
    int pathfinding;
    Position *position;
} Monster;



int killMonster(Monster *monster);

void drawMonster(Monster *monster);

Monster *selectMonster(int level);

Monster *createMonster(char tile, int health, int attack, int speed,
                       int defence, int pathfinding);

int setStartPosition(Monster *monster, Room *room);