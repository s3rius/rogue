#include <game.h>
#include <position.h>
#include <level.h>
#include "rogue.h"

void render(Game *game){
  clear();
  renderGameHUD(game->level);
  drawLevel(game->level);
}

int gameLoop(Game *game) {
  Position *position;
  Level *level;
  if (game->initialized){
    level = game->level;
  } else{
    game->level = createLevel(game->reachedLeavel);
    game->initialized = 1;
    level = game->level;
  }

  int ch = '\0';
  while (ch != 'q') {
    position = handleInput(ch, level->user);
    if (position->x != level->user->position->x || position->y != level->user->position->y) {
      checkPosition(position, level);
      moveMonsters(level);
    }
    render(game);
    if (level->user->health < 1) {
      game->reachedLeavel = 1;
      return -1;
    }
    ch = getch();
  }
  return 1;
}