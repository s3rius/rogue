#ifndef ROGUE_H
#define ROGUE_H

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
  int numberOfDoors;
  struct Door **doors;
  // Monster ** monsters;
  // Item ** items;
} Room;

typedef struct Door {
  Position position;
  int connected;
} Door;

typedef struct Player {
  Position *position;
  int health;
  int attack;
  int maxHealth;
  int gold;
  int exp;
} Player;

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
/*    GLOBALS   */

int MAX_HEIGHT;
int MAX_WIDTH;

/* Screen functions */
int screen_setup();

int printGameHUD(Level *level);

/* Functions for map setup */
Room **roomsSetUp(Level *level);

int placePlayer(Room **rooms, Player *user);

char **saveLevelPositions();

Level *createLevel(int level);

Room *createRoom(int grid, int numberOfDoors);

int drawRoom(Room *room);

void connectDoors(Level *level);

/* Functions for player */
Player *playerSetUp();

Position *handleInput(int input, Player *user);

int playerMove(Position *position, Player *user, char **level);

int checkPosition(Position *position, Level *level);

/* Functions for monsters */

int addMonsters(Level *level);

Monster *selectMonster(int level);

Monster *createMonster(char tile, int health, int attack, int speed,
                       int defence, int pathfinding);

int setStartPosition(Monster *monster, Room *room);

int moveMonsters(Level *level);

int pathfindingSeek(Position *start, Position *dst);

int pathFindingRandom(Position *position);

Monster *getMonsterAt(Position *position, Monster **monsters);

int combat(Player *player, Monster *monster, int order);

int killMonster(Monster *monster);

#endif