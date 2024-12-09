#include "dice_face.h"

#ifndef DICE_H
#define DICE_H

typedef struct Die {
    DieFace faces[6];
} Die;

// TODO: switch to pass by reference to directly modify the die
int set_face(Die, int, DieFace);
int upgrade_face(Die, int, int);

#endif