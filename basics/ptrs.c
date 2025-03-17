#include <stdio.h>

int calculateArraySize(int array[]) {
    int result = sizeof(array) / sizeof(int);
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    
    printf("%lu", calculateArraySize(&array));
    
    return 0;
}