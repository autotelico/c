#include <stdio.h>

int main(void) {
    printf("%6d, %4d\n", 84, 1040);
    /* 
        It prepares 6 places, but only receives 2, so the
        rest of the places are filled out by blank spaces.
    */

    printf("%12.5e\n", 30.253);
    /*

    */
    
    printf("%.4f\n", 83.162);
    /**
        It says 4 digits are to be show after the decimal point. So the number is 83.1620
     */
    printf("%-6.2g\n", .0000009979);
    /*
        Rounds the number (0.000001), converts the number to the exponential form (1e-06), 
        then displays it.
    */

    return 0;
}