#ifndef DICE_FACE_H
#define DICE_FACE_H

#endif

// TODO: use pointers to allow the effects list to have dynamic length
typedef struct DieFace {
    // effect, value, secondary, repeat
    int effects [1][4];
} DieFace;