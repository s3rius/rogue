#include "rogue.h"

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
  int monster;
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
  }

  // mvprintw(0,0, "Monster: %d", monster);
  // getch();
  switch (monster) {
  case 1:
    return createMonster('S', 2, 1, 1, 1, 1);
    break;
  case 2:
    return createMonster('G', 5, 3, 1, 1, 2);
    break;
  case 3:
    return createMonster('T', 15, 5, 1, 1, 1);
    break;
  default:
    return createMonster('S', 2, 1, 1, 1, 1);
  }
}

/*
 * Spider:
 *  tile: S
 *  attack: 1
 *  speed: 1
 *  levels: 1-3;
 *  health: 2
 *  defence: 1
 *  pathfinding: 1 (random movement)
 *
 * Goblin:
 *  tile: G
 *  attack: 3
 *  speed: 1
 *  levels: 1-6
 *  health: 5
 *  defence: 1
 *  pathfinding: 2 (seeking)
 *
 * Troll:
 *  tile: T
 *  attack: 5
 *  health: 15
 *  speed: 1
 *  defence: 1
 *  pathfinding: 1 (random movement)
 */

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

  sprintf(newMonster->str, "%c", tile);
  return newMonster;
}

int moveMonsters(Level *level) {
  for (int i = 0; i < level->numberOfMonsters; i++) {
    mvprintw(level->monsters[i]->position->y, level->monsters[i]->position->x,
             ".");
    if (level->monsters[i]->pathfinding == 1) {
      pathFindingRandom(level->monsters[i]->position);
    } else {
      pathfindingSeek(level->monsters[i]->position, level->user->position);
    }
    mvprintw(level->monsters[i]->position->y, level->monsters[i]->position->x,
             level->monsters[i]->str);
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
