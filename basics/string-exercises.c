#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getLength(char *text) {
    return strlen(text);
}

char* makeCopy(char *text) {
    char* textCopy = (char*) malloc(strlen(text) + 1);
    if (textCopy == NULL) {
        printf("Memory allocation failed. Exiting with code 1");
        exit(1);
    }
    strcpy(textCopy, text);
    return textCopy;
}

char* reverseString(char* text) {
    int textLength = strlen(text);
    char* textCopy = (char*) malloc(textLength + 1);
    if (textCopy == NULL) {
        printf("Memory allocation failed at reverseString");
        exit(1);
    }
    for (int i = 0; text[i] != 0; i++) {
        textCopy[textLength - i - 1] = text[i];
    }
    textCopy[textLength] = '\0';
    return textCopy;
}


int main(void) {
    char initialText[] = "Wassup";
    int length = getLength(initialText);
    char* textCopy = makeCopy(initialText);
    char* concatenated = (char*) malloc(strlen(initialText) + strlen(textCopy) + 1);
    char* reversedString = reverseString(initialText);
    printf("Length: %d\n", length); 
    printf("initialText: %s\n", initialText);
    printf("textCopy: %s\n", textCopy);
    strcpy(concatenated, initialText);
    strcat(concatenated, textCopy);
    printf("Concatenating original with copy: %s\n", concatenated);
    printf("Are the strings equal? %s\n", (strcmp(initialText, textCopy) == 0) ? "True" : "False");
    printf("Reversed string: %s\n", reversedString);
    free(textCopy);
    free(concatenated);
    free(reversedString);

    return 0;
}