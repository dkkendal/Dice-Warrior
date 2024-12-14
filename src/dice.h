#ifndef DICE_H
#define DICE_H
#include "die_face.h"

// TODO: make faces a dynamically sized array to allow for difficulty settings
typedef struct Die {
    DieFace* faces;
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

Die generate_easy_die(char* die_code){
    for(int i=0; i<ARRAY_LENGTH(die_code); i++){
        // do stuff
    }
}

Die generate_normal_die(char* die_code){
    for(int i=0; i<ARRAY_LENGTH(die_code); i++){
        // do stuff
    }
}

Die generate_hard_die(char* die_code){
    for(int i=0; i<ARRAY_LENGTH(die_code); i++){
        // do stuff
    }
}

Die generate_showoff_die(char* die_code){
    for(int i=0; i<ARRAY_LENGTH(die_code); i++){
        // do stuff
    }
}

Die generate_excessive_die(char* die_code){
    for(int i=0; i<ARRAY_LENGTH(die_code); i++){
        // do stuff
    }
}

Die generate_why_die(char* die_code){
    for(int i=0; i<ARRAY_LENGTH(die_code); i++){
        // do stuff
    }
}

Die generate_die(char* die_code, int difficulty){
    switch (difficulty)
    {
    case 0:
        return generate_easy_die(die_code);
        break;
    case 1:
        return generate_normal_die(die_code);
        break;
    case 2:
        return generate_hard_die(die_code);
        break;
    case 3:
        return generate_showoff_die(die_code);
        break;
    case 4:
        return generate_excessive_die(die_code);
        break;
    case 5:
        return generate_why_die(die_code);
        break;
    default:
        // invalid difficulty provided
        break;
    }
}

#endif