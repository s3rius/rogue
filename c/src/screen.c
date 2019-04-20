#include "rogue.h"


int screen_setup() {
  initscr();
  noecho();
  refresh();
  
  return 1;
}

int printGameHUD(Level *level)
{
  mvprintw(25, 0, "    Level: %d", level->level);
  printw("    Gold: %d", level->user->gold);
  printw("    HP: %d(%d)", level->user->health, level->user->maxHealth);
  printw("    Attack: %d", level->user->attack);
  printw("    EXP: %d", level->user->exp);
  printw("           ");
  return 1;
}
