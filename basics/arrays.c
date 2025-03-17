#include <stdio.h>

int main() {
    const int myArray[] = {1, 2, 3, 4, 5};
    int myArraySize = sizeof(myArray) / (int) sizeof(int);
    for (int i = 0 ; i < myArraySize; i++) {
        printf("%d\n", myArray[i]);
    }

    printf("Sizeof int: %d\n", (int) sizeof(int));
    
    return 0;
}