#include <mainMenu.h>
#include "rogue.h"

int gameLoop() {
  Position *position;
  Level *level;

  level = createLevel(1);
  printGameHUD(level);
  int ch;
  while ((ch = getch()) != 'q') {
    printGameHUD(level);
    position = handleInput(ch, level->user);
    checkPosition(position, level);
    moveMonsters(level);
    move(level->user->position->y, level->user->position->x);
    if (level->user->health < 1) {
      return -1;
    }
  }
  return 1;
}

void menuLoop() {
  int choise;
  char *menuChoices[] = {"Start game", "Settings", "Quit"};
  while (true) {
    choise = mainMenu(3, menuChoices);
    switch (choise) {
      case START_GAME:
        if (gameLoop() == -1) {
//          TODO: DeathScreen
//          show_death_screen();
        }
        clear();
        break;
      case SETTINGS:
        break;
      case QUIT:
        return;
    }
  }
}

int main() {
  screen_setup();
  srand(time(NULL));
  menuLoop();
  endwin();
  return 0;
}
