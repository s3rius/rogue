#pragma once

#include "position.h"

int checkTile(int y, int x);

int addNeighbours(int **frontier, int frontierCount, int ***cameFrom, int y,
                  int x);

void pathFind(Position *start, Position *end);
