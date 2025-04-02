#include <stdio.h>
#include <stdlib.h>

int* createEmptyArray() {
    int arraySize = sizeof(int) * 4;
    int* array = (int*) malloc(arraySize);
    for (int i = 0; i < arraySize; i++) {
        array[i] = 0;
    }
    return array;
}

int main(void) {
    int *myArray = createEmptyArray();
    printf("%d\n", *myArray);
    free(myArray);
    return 0;
}