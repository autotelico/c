#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* toLowercase(char s[]) {
    int sLen = strlen(s) + 1;
    char* sCopy = (char*) malloc(sLen);
    if (sCopy == NULL) {
        printf("Malloc error here!!");
        exit(1);
    }
    strcpy(sCopy, s);
    for (int i = 0; sCopy[i] != '\0'; i++) {
        sCopy[i] = tolower(sCopy[i]);
    }
    return sCopy;
}