#pragma once
#include "position.h"

typedef struct Player {
    Position *position;
    int health;
    int attack;
    int maxHealth;
    int gold;
    int exp;
} Player;

Player *playerSetUp();

Position *handleInput(int input, Player *user);

int playerMove(Position *position, Player *user);

void drawPlayer(Player *player);