#pragma once

typedef enum {SWORD, SPEAR} WeaponType;

typedef struct Weapon{
  WeaponType type;
  int attack;
  int health;
} Weapon;