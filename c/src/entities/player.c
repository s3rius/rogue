#include <player.h>
#include <level.h>
#include <combat.h>
#include "rogue.h"

Player *playerSetUp() {
  int inventorySize = 25;
  Player *newPlayer;
  newPlayer = malloc(sizeof(Player));
  newPlayer->position = malloc(sizeof(Position));
  newPlayer->items = malloc(sizeof(Item *));
  newPlayer->position->x = 14;
  newPlayer->position->y = 14;

  newPlayer->attack = 1;
  newPlayer->health = 20;
  newPlayer->maxHealth = 20;
  newPlayer->gold = 0;
  newPlayer->exp = 0;
  newPlayer->numberOfItems = 0;
  newPlayer->inventorySize = inventorySize;

  newPlayer->items[newPlayer->numberOfItems] = createSword(1, 20);
  newPlayer->numberOfItems++;
  return newPlayer;
}

int placePlayer(Room **rooms, Player *user){
  user->position->x = rooms[3]->position.x + 1;
  user->position->y = rooms[3]->position.y + 1;

  return 1;
}

Position *handleInput(int input, Player *user) {
  Position *newPosition;
  newPosition = malloc(sizeof(Position));

  switch (input) {
  case 'w':
  case 'W':
    newPosition->y = user->position->y - 1;
    newPosition->x = user->position->x;
    break;

  case 'a':
  case 'A':
    newPosition->y = user->position->y;
    newPosition->x = user->position->x - 1;
    break;

  case 's':
  case 'S':
    newPosition->y = user->position->y + 1;
    newPosition->x = user->position->x;
    break;

  case 'd':
  case 'D':
    newPosition->y = user->position->y;
    newPosition->x = user->position->x + 1;
    break;

  default:
    newPosition->x = user->position->x;
    newPosition->y = user->position->y;
    break;
  }

  return newPosition;
}

int playerMove(Position *position, Player *user) {
  user->position->x = position->x;
  user->position->y = position->y;
  return 0;
}

int checkPosition(Position *position, Level *level) {
  // int space;
  switch (mvinch(position->y, position->x)) {
  case '.':
  case '#':
  case '+':
    playerMove(position, level->user);
    break;
  case 'S':
  case 'G':
  case 'T':
    combat(level->user, getMonsterAt(position, level->monsters), 1);
  default:
    move(level->user->position->y, level->user->position->x);
    break;
  }

  return 0;
}

void drawPlayer(Player *player)
{
  mvprintw(player->position->y, player->position->x, "@");
  move(player->position->y, player->position->x);
}
