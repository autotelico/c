#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int myArraySize = sizeof(myArray) / sizeof(int);
    int *arrayCopy = (int*) malloc(myArray);
    memcpy(arrayCopy, myArray, sizeof(myArray[0]));
    for (int i = 0; i < myArraySize; i++) {
        printf("%d\n", arrayCopy[i]);
    }
    free(arrayCopy);
    return 0;
}