#include "rogue.h"

// typedef struct Level{
// char ** tiles;
// int level;
// int numberOfRooms;
// int numberOfMonsters;
// struct Room ** rooms;
// struct Monster ** monsters;
//
// } Level;

Level *createLevel(int level) {
  Level *newLevel;
  newLevel = malloc(sizeof(Level));
  newLevel->level = level;
  newLevel->numberOfRooms = 3;
  newLevel->rooms = roomsSetUp();
  newLevel->tiles = saveLevelPositions();
  newLevel->user = playerSetUp();
  placePlayer(newLevel->rooms, newLevel->user);
  addMonsters(newLevel);
  return newLevel;
}

Room **roomsSetUp() {
  Room **rooms;
  rooms = malloc(sizeof(Room) * 6);
  for (int i = 0; i < 6; i++) {
    rooms[i] = createRoom(i);
    drawRoom(rooms[i]);
  }
  // rooms[0] = createRoom(13, 13, 6, 8);
  // drawRoom(rooms[0]);
  //
  // rooms[1] = createRoom(2, 40, 6, 8);
  // drawRoom(rooms[1]);
  //
  // rooms[2] = createRoom(10, 40, 6, 8);
  // drawRoom(rooms[2]);
  //
  // connectDoors(&rooms[0]->doors[3], &rooms[2]->doors[2]);
  // connectDoors(&rooms[1]->doors[2], &rooms[0]->doors[0]);

  return rooms;
}

char **saveLevelPositions() {
  // int x;
  // int y;
  char **positions;
  positions = malloc(sizeof(char *) * 25);
  for (int y = 0; y < 25; y++) {
    positions[y] = malloc(sizeof(char) * 100);
    for (int x = 0; x < 100; x++) {
      positions[y][x] = mvinch(y, x);
    }
  }
  return positions;
}
