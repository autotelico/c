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

struct Book *findBookByTitle(char bookTitle[], struct Book bookArray[], int bookArraySize)
{
    char bookTitleCopy[50];
    strcpy(bookTitleCopy, bookTitle);

    for (int i = 0; i < bookArraySize; i++)
    {
        char bookArrayTitleCopy[50];
        strcpy(bookArrayTitleCopy, bookArray[i].title);
        char *lcBookArrayTitleCopy = toLowercase(bookArrayTitleCopy);
        char *lcBookTitleCopy = toLowercase(bookTitleCopy);

        printf("[%s | %s]\n", bookArrayTitleCopy, bookTitleCopy);
        if (strcmp(lcBookArrayTitleCopy, lcBookTitleCopy) == 0)
        {
            printf("Book found!!!\n");
            return &bookArray[i];
        }
    }
}