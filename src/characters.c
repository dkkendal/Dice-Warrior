#include "dice.h"

Die get_character(int character_id){
    Die temp_die;
    switch (character_id)
    {
    case 0:
        // warrior, // 4 attacks, 2 defends
        break;
    case 1:
    // rogue, // 3 attacks, 2 hides, 1 evade
        break;
    case 2:
    // mage, // 1 attack, 1 defend, 1 heal, 1 strengthen, 1 fortify, 1 vigor
        break;
    case 3:
    // paladin, // 2 attacks, 2 defends, 1 heal, 1 fortify
        break;
    case 4:
    // vampire, // 2 attack/heal, 1 strengthen, 1 vigor, 2 dud
        break;
    case 5:
    // pyromancer, // 2 burn attacks, 2 burn defends, 2 burns (base value on hybrid actions lower)
        break;
    case 6:
    // cryomancer, // 3 freeze attacks, 3 freeze (relies on freezing enemies to protect themselves)
        break;
    case 7:
    // warlock, // 2 regen enemy, 2 channel regen, 1 poison enemy, 1 regen self. Give the enemy regen, convert it into regen for yourself or poison on the enemy.
        break;
    default:
        // random character, generate random number then return the recursion result
        break;
    }
    return temp_die;
};