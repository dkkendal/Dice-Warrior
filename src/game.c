#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE (0x400)

char * searchReplace(char * string, char *toReplace[], char *replacements[], int numReplacements){
    int i = 0;
    char *locOfToRep;
    char *toRep;
    char *rep;
    int lenToRep,lenStr,lenAfterLocRep;
    static char buffer[MAX_SOURCE_SIZE];
    for(i = 0; i < numReplacements; ++i){
        toRep = toReplace[i];
        rep = replacements[i];
        //if str not in the string, exit.
        if (!(locOfToRep = strstr(string,toRep))){exit(EXIT_FAILURE);}
        lenToRep = strlen(toRep);
        lenStr = strlen(string);
        lenAfterLocRep = strlen(locOfToRep);
        sprintf(buffer, "%.*s%s%s", lenStr-lenAfterLocRep, string,rep,locOfToRep+lenToRep);
        string = buffer;
    }
    return buffer;
}

struct EffectData {
    char name[12];
    int ratio; // Divide value by ratio to get the end result. So an effect of value 10 with ratio 3 would have a final result of 3.
    char description[128]; // 128 should be enough space, but we'll see
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
    "add secondary", // allows an effect with a secondary effect to have another. For example, this could change a purge [burn] into a purge [burn, poison]. Applying this to channel allows it to remove either type of debuff totalling up to the channel value.
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
    struct EffectData effects[25];

    if(reader == NULL){
        printf("Error opening effects file");
        return 1;
    }
    else {
        char buffer[256];
        int row=0, column=0;

        while(fgets(buffer, 256, reader)){
            column=0;

            char* value = strtok(buffer, ", ");

            while(value){
                switch (column)
                {
                case 0:
                    strcpy(effects[row].name, value);
                    break;
                case 1:
                    effects[row].ratio = value;
                    break;
                case 2:
                    if(effects[row].ratio == 1){
                        strcpy(effects[row].description, value);
                    }
                    else{
                        char* temp;
                        sprintf(temp, "1/%d", effects[row].ratio);
                        strcpy(effects[row].description, searchReplace(value, "[ratio]", temp, 1));
                    }
                    break;
                }
                column++;
            }

            row++;
        }
        fclose(reader);
    }

    printf(effects);

    return 0;
};