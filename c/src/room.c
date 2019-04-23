#include <room.h>
#include "rogue.h"

int drawRoom(Room *room) {
  int x;
  int y;
  for (x = room->position.x; x < room->position.x + room->width; x++) {
    mvprintw(room->position.y, x, "-");
    mvprintw(room->position.y + room->height, x, "-");
  }

  for (y = room->position.y + 1; y < room->position.y + room->height; y++) {
    mvprintw(y, room->position.x, "|");
    mvprintw(y, room->position.x + room->width - 1, "|");
    for (x = room->position.x + 1; x < room->position.x + room->width - 1;
         x++) {
      mvprintw(y, x, ".");
    }
  }

  for (int i = 0; i < room->numberOfDoors; i++) {
    Position doorPosition;
    doorPosition = room->doors[i]->position;
    mvprintw(doorPosition.y, doorPosition.x, "+");
  }

  return 1;
}

// int connectDoors(Position *doorOne, Position *doorTwo) {
// Position tmp;
// Position previous;
//
// int count = 0;
//
// tmp.x = doorOne->x;
// tmp.y = doorOne->y;
//
// previous = tmp;
//
// while (true) {
// if (tmp.x == doorTwo->x && tmp.y == doorTwo->y) {
// break;
// } else if ((abs((tmp.x - 1) - doorTwo->x) < abs(tmp.x - doorTwo->x)) &&
// (mvinch(tmp.y, tmp.x - 1) == ' ')) {
// previous.x = tmp.x;
// tmp.x -= 1;
// } else if ((abs((tmp.x + 1) - doorTwo->x) < abs(tmp.x - doorTwo->x)) &&
// (mvinch(tmp.y, tmp.x + 1) == ' ')) {
// previous.x = tmp.x;
// tmp.x += 1;
// } else if ((abs((tmp.y + 1) - doorTwo->y) < abs(tmp.y - doorTwo->y)) &&
// (mvinch(tmp.y + 1, tmp.x) == ' ')) {
// previous.y = tmp.y;
// tmp.y += 1;
// } else if ((abs((tmp.y - 1) - doorTwo->y) < abs(tmp.y - doorTwo->y)) &&
// (mvinch(tmp.y - 1, tmp.x) == ' ')) {
// previous.y = tmp.y;
// tmp.y -= 1;
// } else {
// if (count == 0) {
// tmp = previous;
// count++;
// continue;
// } else {
// return 0;
// }
// }
// mvprintw(tmp.y, tmp.x, "#");
// }
//
// return 1;
// }

Room *createRoom(int grid, int numberOfDoors) {
  Room *newRoom;
  newRoom = malloc(sizeof(Room));
  newRoom->numberOfDoors = numberOfDoors;
  switch (grid) {
  case 0:
    newRoom->position.x = 0;
    newRoom->position.y = 0;
    break;
  case 1:
    newRoom->position.x = 33;
    newRoom->position.y = 0;
    break;
  case 2:
    newRoom->position.x = 66;
    newRoom->position.y = 0;
    break;
  case 3:
    newRoom->position.x = 0;
    newRoom->position.y = 14;
    break;
  case 4:
    newRoom->position.x = 33;
    newRoom->position.y = 14;
    break;
  case 5:
    newRoom->position.x = 66;
    newRoom->position.y = 14;
    break;
  default:
    newRoom->position.x = 0;
    newRoom->position.y = 0;
  }

  newRoom->height = (rand() % 6) + 4;
  newRoom->width = (rand() % 14) + 4;

  newRoom->position.x += rand() % (30 - newRoom->width) + 1;
  newRoom->position.y += rand() % (10 - newRoom->height) + 1;

  newRoom->doors = malloc(sizeof(Door *) * numberOfDoors);

  for (int i = 0; i < numberOfDoors; i++) {
    newRoom->doors[i] = malloc(sizeof(Door));
    newRoom->doors[i]->connected = 0;
  }

  /* Top door */
  newRoom->doors[0]->position.x =
      newRoom->position.x + (rand() % (newRoom->width - 2)) + 1;
  newRoom->doors[0]->position.y = newRoom->position.y;
  
  /* Bottom door */
  newRoom->doors[1]->position.x =
      newRoom->position.x + (rand() % (newRoom->width - 2)) + 1;
  newRoom->doors[1]->position.y = newRoom->position.y + newRoom->height;

  /* Left door */
  newRoom->doors[2]->position.x = newRoom->position.x;
  newRoom->doors[2]->position.y =
      newRoom->position.y + (rand() % (newRoom->height - 2)) + 1;

  /* Right door */
  newRoom->doors[3]->position.x = newRoom->position.x + newRoom->width - 1;
  newRoom->doors[3]->position.y =
      newRoom->position.y + (rand() % (newRoom->height - 2)) + 1;

  return newRoom;
}
