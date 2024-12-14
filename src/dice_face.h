#ifndef DICE_FACE_H
#define DICE_FACE_H

#endif

// TODO: use pointers to allow the effects list to have dynamic length
typedef struct DieFace {
    int value;
    // effect, secondary, repeat (default repeat is 0)
    int effects [1][3];
} DieFace;