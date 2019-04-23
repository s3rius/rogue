#include "rogue.h"
#include <item.h>
#include "item.h"

 Item *createSword(int attack, int health){
  Item *item = malloc(sizeof(Item));
  item->type = WEAPON;
  strcpy(item->string, "Sword");
  Weapon *weapon = malloc(sizeof(Weapon));

  weapon->health = health;
  weapon->attack = attack;
  weapon->type = SWORD;

  item->item.weapon = weapon;
  return item;
}