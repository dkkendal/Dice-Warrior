#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "characters.h"
#include "effects.h"
#include "upgrades.h"

int main(int argc, char **argv) {
    for(int i=0; i<ARRAY_LENGTH(effect_list); i++){
        printf("Name: %s, Ratio: %d, Description: %s\n", effect_list[i].name, effect_list[i].ratio, effect_list[i].description);
    }

    return 0;
};