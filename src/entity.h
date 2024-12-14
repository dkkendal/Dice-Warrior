#include "dice.h"

#ifndef ENTITY_H
#define ENTITY_H

// TODO: use pointers to allow the dice list to have dynamic length
// Most entities will start with 0 of all buffs, debuffs, and status effects, but some do not
typedef struct Entity
{
    int is_player; // 0: enemy, 1: player
    int health;
    int buffs[9], debuffs[10];
    Die dice[3];
} Entity;

// TODO: functions for hp gain, loss, buff/debuff application/activation

#endif