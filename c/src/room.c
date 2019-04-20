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

  for (int i = 0; i < 4; i++) {
    Position doorPosition = room->doors[i];
    mvprintw(doorPosition.y, doorPosition.x, "+");
  }

  return 1;
}
int connectDoors(Position *doorOne, Position *doorTwo) {
  Position tmp;
  Position previous;

  int count = 0;

  tmp.x = doorOne->x;
  tmp.y = doorOne->y;

  previous = tmp;

  while (true) {
    if (tmp.x == doorTwo->x && tmp.y == doorTwo->y) {
      break;
    } else if ((abs((tmp.x - 1) - doorTwo->x) < abs(tmp.x - doorTwo->x)) &&
               (mvinch(tmp.y, tmp.x - 1) == ' ')) {
      previous.x = tmp.x;
      tmp.x -= 1;
    } else if ((abs((tmp.x + 1) - doorTwo->x) < abs(tmp.x - doorTwo->x)) &&
               (mvinch(tmp.y, tmp.x + 1) == ' ')) {
      previous.x = tmp.x;
      tmp.x += 1;
    } else if ((abs((tmp.y + 1) - doorTwo->y) < abs(tmp.y - doorTwo->y)) &&
               (mvinch(tmp.y + 1, tmp.x) == ' ')) {
      previous.y = tmp.y;
      tmp.y += 1;
    } else if ((abs((tmp.y - 1) - doorTwo->y) < abs(tmp.y - doorTwo->y)) &&
               (mvinch(tmp.y - 1, tmp.x) == ' ')) {
      previous.y = tmp.y;
      tmp.y -= 1;
    } else {
      if (count == 0) {
        tmp = previous;
        count++;
        continue;
      } else {
        return 0;
      }
    }
    mvprintw(tmp.y, tmp.x, "#");
  }

  return 1;
}


Room *createRoom(int grid) {
  Room *newRoom;
  newRoom = malloc(sizeof(Room));
  // newRoom->position.x = x;
  // newRoom->position.y = y;
  // newRoom->height = height;
  // newRoom->width = width;
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
  }

  newRoom->height = (rand() % 6) + 4;
  newRoom->width = (rand() % 14) + 4;

  newRoom->position.x += (rand() %  (29 - newRoom->width + 1));
  newRoom->position.y += (rand() %  (9 - newRoom->height + 1));

  /* Top door */
  newRoom->doors[0].x = newRoom->position.x + (rand() % (newRoom->width - 2)) + 1;
  newRoom->doors[0].y = newRoom->position.y;

  /* Bottom door */
  newRoom->doors[1].x = newRoom->position.x + (rand() % (newRoom->width - 2)) + 1;
  newRoom->doors[1].y = newRoom->position.y + newRoom->height;

  /* Left door */
  newRoom->doors[2].x = newRoom->position.x;
  newRoom->doors[2].y = newRoom->position.y + (rand() % (newRoom->height - 2)) + 1;

  /* Right door */
  newRoom->doors[3].x = newRoom->position.x + newRoom->width - 1;
  newRoom->doors[3].y = newRoom->position.y + (rand() % (newRoom->height - 2)) + 1;

  return newRoom;
}
