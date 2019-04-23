#include <level.h>
#include "rogue.h"


int screen_setup() {
  MAX_HEIGHT = 25;
  MAX_WIDTH = 100;
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  refresh();
  
  return 1;
}

int renderGameHUD(Level *level)
{
  mvprintw(25, 0, "    Level: %d", level->level);
  printw("    Gold: %d", level->user->gold);
  printw("    HP: %d(%d)", level->user->health, level->user->maxHealth);
  printw("    Attack: %d", level->user->attack);
  printw("    EXP: %d", level->user->exp);
  printw("           ");
  return 1;
}
