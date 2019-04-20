#include "rogue.h"

Player *playerSetUp() {
  Player *newPlayer;
  newPlayer = malloc(sizeof(Player));
  newPlayer->position = malloc(sizeof(Position));
  
  newPlayer->position->x = 14;
  newPlayer->position->y = 14; 
 
  newPlayer->attack = 1;
  newPlayer->health = 20;
  newPlayer->maxHealth = 20;
  newPlayer->gold = 0;
  newPlayer->exp = 0;

  mvprintw(newPlayer->position->y, newPlayer->position->x, "@");
  move(newPlayer->position->y, newPlayer->position->x);

  return newPlayer;
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

int playerMove(Position *position, Player *user, char **level) {
  char buffer[8];

  sprintf(buffer, "%c", level[user->position->y][user->position->x]);
  mvprintw(user->position->y, user->position->x, buffer);

  user->position->x = position->x;
  user->position->y = position->y;

  mvprintw(user->position->y, user->position->x, "@");

  move(user->position->y, user->position->x);
  return 0;
}

int checkPosition(Position *position, Level *level) {
  // int space;
  switch (mvinch(position->y, position->x)) {
  case '.':
  case '#':
  case '+':
    playerMove(position, level->user, level->tiles);
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
