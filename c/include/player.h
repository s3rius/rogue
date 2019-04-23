#pragma once
#include "position.h"
#include "item.h"

typedef struct Player {
    int inventorySize;
    int numberOfItems;
    int health;
    Position *position;
    int attack;
    Item **items;
    int maxHealth;
    int gold;
    int exp;
} Player;

Player *playerSetUp();

Position *handleInput(int input, Player *user);

int playerMove(Position *position, Player *user);

void drawPlayer(Player *player);