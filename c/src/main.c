#include <mainMenu.h>
#include <game.h>
#include <level.h>
#include "rogue.h"



void menuLoop() {
  int choise;
  Game game;
  game.initialized = 0;
  game.reachedLeavel = 1;

  char *menuChoices[] = {"Start game", "Settings", "Quit"};
  int numberOfMenuItems = 3;
  int isPasuse = 0;
  while (true) {
    choise = mainMenu(numberOfMenuItems, menuChoices);
    switch (choise) {
      case START_GAME:
        if (gameLoop(&game) == -1) {
//          TODO: DeathScreen
//          show_death_screen();
        }else{
          menuChoices[0] = "Resume game";
          menuChoices[1] = "Reset game";
          menuChoices[2] = "Go to main menu";
          isPasuse = 1;
        }
        clear();
        break;
      case SETTINGS:
        if (isPasuse){
          menuChoices[0] = "Start game";
          game.initialized = 0;
        }
        break;
      case QUIT:
        if (isPasuse){
          game.initialized = 0;
          isPasuse = 0;
          menuChoices[0] = "Start game";
          menuChoices[1] = "Settings";
          menuChoices[2] = "Quit";
        }else {
          return;
        }
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
