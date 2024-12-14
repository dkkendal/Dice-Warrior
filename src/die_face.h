#ifndef DIE_FACE_H
#define DIE_FACE_H

// TODO: use pointers to allow the effects and upgrades list to have dynamic length
typedef struct DieFace {
    int value;
    // effect, secondary, repeat (default repeat is 0)
    int effects [1][3];
    int upgrades [12];
} DieFace;

#endif
