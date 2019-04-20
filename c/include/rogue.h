#ifndef ROGUE_H
#define ROGUE_H
#endif

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct Level {
  char **tiles;
  int level;
  int numberOfRooms;
  int numberOfMonsters;
  struct Player *user;
  struct Room **rooms;
  struct Monster **monsters;

} Level;

typedef struct Position {
  int x;
  int y;
} Position;

typedef struct Room {
  Position position;
  int height;
  int width;
  Position doors[4];
  // Monster ** monsters;
  // Item ** items;
} Room;

typedef struct Player {
  Position *position;
  int health;
} Player;

typedef struct Monster {
  char str[2];
  char tile;
  int health;
  int attack;
  int speed;
  int defence;
  int pathfinding;
  Position *position;
} Monster;

int screen_setup();

/* Functions for map setup */
Room **roomsSetUp();

char **saveLevelPositions();

Level *createLevel(int level);

Room *createRoom(int y, int x, int height, int width);

int drawRoom(Room *room);

int connectDoors(Position *doorOne, Position *doorTwo);

/* Functions for player */
Player *playerSetUp();

Position *handleInput(int input, Player *user);

int playerMove(Position *position, Player *user, char **level);

int checkPosition(Position *position, Player *user, char **level);

/* Functions for monsters */

int addMonsters(Level *level);

Monster *selectMonster(int level);

Monster *createMonster(char tile, int health, int attack, int speed,
                       int defence, int pathfinding);

int setStartPosition(Monster *monster, Room *room);

int moveMonsters(Level *level);

int pathfindingSeek(Position *start, Position *dst);

int pathFindingRandom(Position *position);
