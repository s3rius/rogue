//
// Created by s3rius on 23.04.19.
//

#pragma once

#include "player.h"
#include "monster.h"

int combat(Player *player, Monster *monster, int order);

Monster *getMonsterAt(Position *position, Monster **monsters);
