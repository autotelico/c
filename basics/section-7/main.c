#include <stdio.h>
#include <limits.h>

int main() {
    /*
        Signed vs. unsigned comparisons can result in unexpected errors.
        Here, j is converted from signed to unsigned by adding the INT_MAX
        value
    */

    unsigned int i = -10;
    signed int j = 10;
    printf("i < j = %d\ni = %d\nj = %d\n", i < j, i, j); // 0. 

    return 0;
}
