#pragma once

#include "position.h"
#include "weapon.h"
#include "potion.h"

typedef enum { WEAPON, POTION } ItemType;

typedef struct Item{
  ItemType type;
  Position *position;
  int equiped;
  union {
      Weapon *weapon;
      Potion *potion;
  } item;

  char string[];

} Item;

Item *createSword(int attack, int health);