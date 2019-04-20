#include "rogue.h"

int main() {

  Player *user;
  int ch;
  screen_setup();
  Position *position;

  srand(time(NULL));
  Level *level;
  
  level = createLevel(1);

  user = playerSetUp();

  while ((ch = getch()) != 'q') {
    position = handleInput(ch, user);
    checkPosition(position, user, level->tiles);
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

