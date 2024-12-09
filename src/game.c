#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "characters.h"
#include "effects.h"

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
        char* endPointer;

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
                    effects[row].ratio = strtol(value, &endPointer, 10);
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