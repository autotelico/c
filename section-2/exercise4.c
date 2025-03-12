#include <stdio.h>

int main(void) {
    int i, j, k;
    float f, g, h;

    printf("Ints: %d, %d, %d\n", i, j, k);
    printf("Floats: %f, %f, %f", f, g, h);
    
    /* 
        There is no pattern to the values printed. They are all garbage values:
        values that are leftovers from previous initializations that used that same
        memory address. They are unpredictable (would say random, but random wouldn't
        be accurate imo since computers have patterns and it's likely that there's a
        pattern somewhere in the memory address selection phase. Would be fun to learn
        about it).
    */
    return 0;
}