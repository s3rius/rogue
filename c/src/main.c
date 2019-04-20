#include "rogue.h"

int main() {

  int ch;
  screen_setup();
  Position *position;

  srand(time(NULL));
  Level *level;
  
  level = createLevel(1);

  while ((ch = getch()) != 'q') {
    position = handleInput(ch, level->user);
    checkPosition(position, level);
    moveMonsters(level);
    move(level->user->position->y, level->user->position->x);
  }

  endwin();
  return 0;
}

int screen_setup() {
  initscr();
  noecho();
  refresh();

  return 1;
}

