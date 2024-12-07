#include <stdio.h>
#include <stdlib.h>

// Buffs/debuffs affecting other actions will be applied to die faces instead of characters.
// On second thought, since die faces will be able to have multiple effects, applying buffs/debuffs to characters might make more sense.
// Might need to limit buffs to fixed effects so they don't become immediately busted though.
const char effects[][12] = {
    // basic actions
    "attack", // damages one target
    "defend", // gives block, preventing incoming damage
    "hide", // provides dodge/crit chance. either activating halves the value
    "heal", // restores hp
    "dud", // does nothing
    // advanced actions
    "purge", // removes all? of a specified effect from the target, if followed by another effect add the purged quantity to that effect's value
    "cleanse", // removes value in buffs/debuffs/status effects from a target, could randomly select things to remove or have a preference list defined and available to the player
    // face buffs (TODO: random or do you choose the face?)
    "strengthen", // attacking
    "fortify", // defending buff
    "evade", // hiding buff
    "vigor", // healing buff
    // face debuffs (TODO: random or do you choose the face?)
    "weaken", // attacking debuff
    "erode", // defending debuff
    "mark", // hiding debuff
    "ennervate", // healing debuff
    // status effects, decrease each turn and/or on activation
    "burn", // damage over time, stacks-1 each turn
    "freeze", // actions with lower value do not happen, remove stacks equal to the value of prevented actions
    "poison", // if poison >= current HP, target dies
    "wound", // increase damage to HP when target is hit
    "curse", // increase status effect applications (burn, freeze, poison, wound)
    "spiked", // deals damage to attackers, can't deal more damage than the attack?
    };

// Whether added dice are treated as additional characters or not, they will be themed around some sort of archetype
const char dieTypes[][10] = {
    "warrior", // 4 attacks, 2 defends
    "rogue", // 3 attacks, 3 hides
    "mage", // 2 attacks, 2 defends, 1 strengthen, 1 fortify
    "paladin", // 2 attacks, 2 defends, 1 heal, 1 fortify
    "vampire", // 2 attack/heal, 1 strengthen, 1 vigor, 2 dud
    "pyromancer", // 2 burn attacks, 2 burn defends, 2 burns (base value on hybrid actions lower)
    "cryomancer", // 3 freeze attacks, 3 freeze (relies on freezing enemies to protect themselves)
    };

// Effects are applied in the order applied to the die face,
// so a vigor face upgraded with healing could benefit from the increased healing immediately,
// while a healing face upgraded with vigor, would perform the heal before gaining the bonus
const char upgrades[][16] = {
    "plus", // adds a fixed value to an effect, costs more depending on the effect
    "repeat", // halves an effect's value (minimum 1) but causes it to apply an extra time
    "flat bonus", // gives a bonus effect that does not scale with face value
    "scaling bonus", // gives a bonus effect that scales with face value
    "result bonus", // gives a bonus effect that scales with the effectiveness of the base action
    "replace effect", // replaces the current effect with a different one, keeping the face value
    "merge", // gives one die face the effects of another, then turns the other into a dud
    "duplicate face", // replaces one die face with another
};

// TODO: use pointers to allow the effects list to have dynamic length
struct DieFace {
    // effect, value, secondary, repeat
    int effects [1][4];
};

struct Die {
    struct DieFace faces[6];
};

// TODO: use pointers to allow the dice list to have dynamic length
struct Entity {
    struct Die dice[3];
};


int main(int argc, char **argv) {
    printf("Testing");

    return 0;
};