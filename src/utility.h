#ifndef UTILITY_H
#define UTILITY_H

#define MAX_SOURCE_SIZE (0x400)
#define ARRAY_LENGTH(x) sizeof(x)/sizeof(x[0])

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

#endif