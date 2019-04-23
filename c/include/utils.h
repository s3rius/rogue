#pragma once

#include "position.h"
#include "player.h"

int checkTile(int y, int x);

int addNeighbours(int **frontier, int frontierCount, int ***cameFrom, int y,
                  int x);

void pathFind(Position *start, Position *end);

void renderInventory(Player *player);