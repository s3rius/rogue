#include "rogue.h"

int main() {

  int ch;
  screen_setup();
  Position *position;

  srand(time(NULL));
  Level *level;
  
  level = createLevel(1);
  printGameHUD(level);
  while ((ch = getch()) != 'q') {
    printGameHUD(level);
    position = handleInput(ch, level->user);
    checkPosition(position, level);
    moveMonsters(level);
    move(level->user->position->y, level->user->position->x);
  }

  endwin();
  return 0;
}

