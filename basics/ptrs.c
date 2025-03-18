#include <stdio.h>
<<<<<<< HEAD
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
=======

int calculateArraySize(int array[]) {
    int result = sizeof(array) / sizeof(int);
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    
    printf("%lu", calculateArraySize(&array));
    
>>>>>>> f343285528498367dfabc0db5fa9284772f12f36
    return 0;
}