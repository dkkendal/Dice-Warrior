#include <stdio.h>
#include <stdlib.h>

struct EffectData {
    const char name[12];
    const int ratio; // Divide value by ratio to get the end result. So an effect of value 10 with ratio 3 would have a final result of 3.
    const char description[128]; // 128 should be enough space, but we'll see
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
    "warlock", // 2 regen enemy, 2 channel regen, 1 poison enemy, 1 regen self. Give the enemy regen, convert it into regen for yourself or poison on the enemy.
    };

// Effects are applied in the order applied to the die face,
// so a vigor face upgraded with healing could benefit from the increased healing immediately,
// while a healing face upgraded with vigor, would perform the heal before gaining the bonus
// TODO: consider removing flat bonus due to the addition of ratios
const char upgrades[][16] = {
    "plus", // adds a fixed value to an effect, costs more depending on the effect
    "repeat", // halves an effect's value (minimum 1) but causes it to apply an extra time
    "sweep", // applies the effect to all valid targets, more interesting on positive die faces if each die is a separate character as in Slice & Dice
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
// Most entities will start with 0 of all buffs, debuffs, and status effects, but some do not
struct Entity {
    int is_player; // 0: enemy, 1: player
    int health;
    int buffs[5], debuffs[4], statuses[4];
    struct Die dice[3];
};


int main(int argc, char **argv) {
    FILE* reader = fopen("effects.csv","r");

    if(!reader){
        printf("Oh no");
        return 1;
    }
    else {
        // stuff
    }    

    return 0;
};