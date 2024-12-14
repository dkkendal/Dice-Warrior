#include "dice.h"

#ifndef CHARACTERS_H
#define CHARACTERS_H

// Whether added dice are treated as additional characters or not, they will be themed around some sort of archetype
// Warrior and Rogue are base types that will be completely replaced by versions with better scaling
enum DieTypes {
    WARRIOR,
    ROGUE,
    MAGE,
    PALADIN, // 2 attacks, 2 defends, 1 heal, 1 fortify
    VAMPIRE, // 2 attack/heal, 1 strengthen, 1 vigor, 2 dud
    PYROMANCER, // 2 burn attacks, 2 burn defends, 2 burns (base value on hybrid actions lower)
    CRYOMANCER, // 3 freeze attacks, 3 freeze (relies on freezing enemies to protect themselves)
    WARLOCK, // 2 regen enemy, 2 channel regen, 1 poison enemy, 1 regen self. Give the enemy regen, convert it into regen for yourself or poison on the enemy.
    };

Die get_character(int character_id){
    // do stuff
};

#endif