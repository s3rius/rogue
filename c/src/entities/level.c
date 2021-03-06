#include <monster.h>
#include "level.h"
#include "rogue.h"
#include "utils.h"

Level *createLevel(int level) {
  Level *newLevel;
  newLevel = malloc(sizeof(Level));
  newLevel->level = level;
  newLevel->numberOfRooms = 6;
  newLevel->rooms = roomsSetUp(newLevel);
  newLevel->user = playerSetUp();
  connectDoors(newLevel);
  newLevel->tiles = saveLevelPositions();
  placePlayer(newLevel->rooms, newLevel->user);
  addMonsters(newLevel);

  return newLevel;
}

Room **roomsSetUp(Level *level) {
  Room **rooms;
  rooms = malloc(sizeof(Room *) * level->numberOfRooms);
  for (int i = 0; i < level->numberOfRooms; i++) {
    rooms[i] = createRoom(i, 4);
    drawRoom(rooms[i]);
  }
  return rooms;
}

void connectDoors(Level *level) {
  int randDoor, randRoom;
  int all_connected = 0;
  int doors_connected = 0;
  while (all_connected == 0) {
    all_connected = 1;
    for (int i = 0; i < level->numberOfRooms; i++) {
      doors_connected = 0;
      for (int j = 0; j < level->rooms[i]->numberOfDoors; j++) {
        if (level->rooms[i]->doors[j]->connected == 1) {
          doors_connected = 1;
          continue;
        }
        randRoom = rand() % level->numberOfRooms;
        randDoor = rand() % level->rooms[randRoom]->numberOfDoors;

        if (level->rooms[randRoom]->doors[randDoor]->connected == 1 ||
            randRoom == i) {
          continue;
        }

        pathFind(&level->rooms[i]->doors[j]->position,
                 &level->rooms[randRoom]->doors[randDoor]->position);
        level->rooms[randRoom]->doors[randDoor]->connected = 1;
        level->rooms[i]->doors[j]->connected = 1;
        doors_connected = 1;
      }
      all_connected = all_connected && doors_connected;
    }
  }
}

char **saveLevelPositions() {
  // int x;
  // int y;
  char **positions;
  positions = malloc(sizeof(char *) * MAX_HEIGHT);
  for (int y = 0; y < MAX_HEIGHT; y++) {
    positions[y] = malloc(sizeof(char) * MAX_WIDTH);
    for (int x = 0; x < MAX_WIDTH; x++) {
      positions[y][x] = (char)mvinch(y, x);
    }
  }
  return positions;
}

void drawLevel(Level *level){
  int x, y, i;
  for (y = 0; y < MAX_HEIGHT; y++) {
    for (x = 0; x < MAX_WIDTH; x++) {
      mvaddch(y,x , level->tiles[y][x]);
    }
  }

  for (i = 0; i < level->numberOfMonsters; ++i) {
      drawMonster(level->monsters[i]);
  }
  drawPlayer(level->user);
}
