//
// Created by s3rius on 22.04.19.
//

#pragma once

typedef struct Game{
    struct Level *level;
    int initialized;
    int reachedLeavel;
}Game;

int gameLoop(Game *game);

void render(Game *game);
