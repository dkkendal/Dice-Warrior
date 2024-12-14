#include "dice_face.h"

#ifndef DICE_H
#define DICE_H

// TODO: make faces a dynamically sized array to allow for difficulty settings
typedef struct Die {
    DieFace faces[6];
} Die;

// TODO: switch to pass by reference to directly modify the die
int set_face(Die target, int face, DieFace new_face){
    // do stuff
}

int upgrade_face(Die target, int face, int upgrade){
    // do stuff
}

int upgrade_cost(Die target, int face, int upgrade){
    // cost will increase with face value and maybe pre-existing upgrades
}

#endif