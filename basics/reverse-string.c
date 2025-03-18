#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char * text) {
    int textSize = (int) strlen(text);
    char* result = (char*) malloc(textSize + 1);
    int curIndex = 0;
    for (int i = textSize - 1; i >= 0; i--) {
        result[curIndex] = text[i];
        curIndex++;
    }
    printf("curIndex at the end of the loop: %d\n", curIndex);
    result[curIndex] = '\0';

    return result;
}

int hasNullTerminator(char text[]) {
    int hasTerm = 0;

    for (int i = 0; i < strlen(text) + 1; i++) {
        if (text[i] == '\0') {
            hasTerm = 1;
        }
    }

    return hasTerm;
}

int main(void) {
    char name[] = "Carlos";
    char *reversedName = reverseString(name);
    printf("%s\n", reversedName);
    printf("hasNullTerminator: %d\n", hasNullTerminator(reversedName));
    free(reversedName);

    return 0;
}