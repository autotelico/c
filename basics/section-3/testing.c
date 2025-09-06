#include <stdio.h>

int main(void) {
    int i, j;
    float f, g;

    /*
        Result acquired from memory leftovers of previous execution on that address
    */
    //printf("i: %f, f: %d", i, f); 
    
    //printf("%10.2f", 123.0);
    //printf("%10d\n", 10); // Creates space on the left side
    //printf("%-10d", 10); // Creates space on the right side
    //printf("\n");

    //printf("%10g", 10.0);
    int number;
    int number2;
    scanf("%d, %d", &number, &number2);
    printf("%d", number);
    return 0;
}