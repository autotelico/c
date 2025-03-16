#include <stdio.h>

int main(void) {
    printf("%6d, %4d\n", 84, 1040);
    /* 
        It prepares 6 places, but only receives 2, so the
        rest of the places are filled out by blank spaces.
    */

    printf("%.4f\n", 83.162);
    printf("%-6.2g\n", .0000009979);

    return 0;
}