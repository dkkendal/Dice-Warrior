#include "dice.h"

#ifndef ENTITY_H
#define ENTITY_H

// TODO: use pointers to allow the dice list to have dynamic length
// Most entities will start with 0 of all buffs, debuffs, and status effects, but some do not
typedef struct entity
{
    int is_player; // 0: enemy, 1: player
    int health;
    int buffs[5], debuffs[4], statuses[4];
    Die dice[3];
};

#endif