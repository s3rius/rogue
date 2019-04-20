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
  monster->position.y = (rand() % (room->height - 2)) + room->position.y + 1;
  monster->position.x = (rand() % (room->width - 2)) + room->position.x + 1;

  char buffer[8];

  sprintf(buffer, "%c", monster->tile);

  mvprintw(monster->position.y, monster->position.x, buffer);
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

  return newMonster;
}
