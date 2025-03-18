#include <stdio.h>
#include <limits.h>

int main() {
    /*
        Signed vs. unsigned comparisons can result in unexpected errors.
        Here, j is converted from signed to unsigned by adding the INT_MAX
        value
    */

    signed int i = -10;
    unsigned int j = 10;
    printf("%d", i < j); // 0. 

    return 0;
}