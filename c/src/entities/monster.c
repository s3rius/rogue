#include <monster.h>
#include "level.h"
#include "utils.h"
#include "rogue.h"
#include "combat.h"

int addMonsters(Level *level) {
  int x;
  level->monsters = malloc(sizeof(Monster *) * 6);
  level->numberOfMonsters = 0;

  for (x = 0; x < level->numberOfRooms; x++) {
    if ((rand() % 2) == 0) {
      level->monsters[level->numberOfMonsters] = selectMonster(level->level);
      setStartPosition(level->monsters[level->numberOfMonsters],
                       level->rooms[x]);
      level->numberOfMonsters++;
    }
  }
  return 0;
}

int setStartPosition(Monster *monster, Room *room) {
  monster->position->y = (rand() % (room->height - 2)) + room->position.y + 1;
  monster->position->x = (rand() % (room->width - 2)) + room->position.x + 1;

  mvprintw(monster->position->y, monster->position->x, monster->str);
  return 1;
}

Monster *selectMonster(int level) {
  int monster = 0;
  switch (level) {
  case 1:
  case 2:
  case 3:
    monster = (rand() % 2) + 1;
    break;
  case 4:
  case 5:
    monster = (rand() % 2) + 2;
    break;
  case 6:
    monster = 3;
    break;
  default:
    monster = (rand() % 3) + 1;
    break;
  }

  // mvprintw(0,0, "Monster: %d", monster);
  // getch();
  switch (monster) {
  case 1:
    return createMonster('S', 2, 1, 1, 1, 1);
  case 2:
    return createMonster('G', 5, 2, 1, 1, 2);
  case 3:
    return createMonster('T', 15, 4, 1, 1, 1);
  default:
    return createMonster('S', 2, 1, 1, 1, 1);
  }
}


Monster *createMonster(char tile, int health, int attack, int speed,
                       int defence, int pathfinding) {
  Monster *newMonster;
  newMonster = malloc(sizeof(Monster));
  newMonster->tile = tile;
  newMonster->health = health;
  newMonster->attack = attack;
  newMonster->speed = speed;
  newMonster->defence = defence;
  newMonster->pathfinding = pathfinding;
  newMonster->position = malloc(sizeof(Position));
  newMonster->alive = 1;
  sprintf(newMonster->str, "%c", tile);
  return newMonster;
}

int moveMonsters(Level *level) {
  for (int i = 0; i < level->numberOfMonsters; i++) {
    if (level->monsters[i]->alive == 0){
      continue;
    }
    if (level->monsters[i]->pathfinding == 1) {
      pathFindingRandom(level->monsters[i]->position);
    } else {
      pathfindingSeek(level->monsters[i]->position, level->user->position);
    }
  }
  return 1;
}

int pathfindingSeek(Position *start, Position *dst) {
  if (abs((start->x - 1) - dst->x) < abs(start->x - dst->x) &&
      mvinch(start->y, start->x - 1) == '.') {
    start->x = start->x - 1;
  } else if (abs((start->x + 1) - dst->x) < abs(start->x - dst->x) &&
             mvinch(start->y, start->x + 1) == '.') {
    start->x = start->x + 1;
  } else if (abs((start->y - 1) - dst->y) < abs(start->y - dst->y) &&
             mvinch(start->y - 1, start->x) == '.') {
    start->y = start->y - 1;
  } else if (abs((start->y + 1) - dst->y) < abs(start->y - dst->y) &&
             mvinch(start->y + 1, start->x) == '.') {
    start->y = start->y + 1;
  }

  return 1;
}

int pathFindingRandom(Position *position) {
  int random;
  random = rand() % 5;

  switch (random) {
  case 0:
    if (mvinch(position->y - 1, position->x) == '.') {
      position->y--;
    }
    break;
  case 1:
    if (mvinch(position->y + 1, position->x) == '.') {
      position->y++;
    }
    break;
  case 2:
    if (mvinch(position->y, position->x - 1) == '.') {
      position->x--;
    }
    break;
  case 3:
    if (mvinch(position->y, position->x + 1) == '.') {
      position->x++;
    }
    break;
  case 4:
    break;
  }

  return 1;
}

Monster *getMonsterAt(Position *position, Monster **monsters) {
  for (int i = 0; i < 6; i++) {
    if ((position->y == monsters[i]->position->y) &&
        (position->x == monsters[i]->position->x)) {
      return monsters[i];
    }
  }

  return NULL;
}

int killMonster(Monster *monster) {
  monster->alive = 0;
  return 1;
}

void drawMonster(Monster *monster){
  if (monster->alive) {
    mvprintw(monster->position->y, monster->position->x, monster->str);
  }
}

