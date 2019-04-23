//
// Created by s3rius on 22.04.19.
//



#pragma once


#include "room.h"
#include "player.h"
typedef struct Level {
    char **tiles;
    int level;
    int numberOfRooms;
    int numberOfMonsters;
    struct Player *user;
    struct Room **rooms;
    struct Monster **monsters;
} Level;

Room **roomsSetUp(Level *level);

int placePlayer(Room **rooms, Player *user);

char **saveLevelPositions();

Level *createLevel(int level);

void drawLevel(Level *level);

Room *createRoom(int grid, int numberOfDoors);

int drawRoom(Room *room);

void connectDoors(Level *level);

int addMonsters(Level *level);

int moveMonsters(Level *level);

int screen_setup();

int renderGameHUD(Level *level);

int pathfindingSeek(Position *start, Position *dst);

int pathFindingRandom(Position *position);

int checkPosition(Position *position, Level *level);