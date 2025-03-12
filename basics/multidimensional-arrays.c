/**
 * Multidimensional arrays
 */

#include <stdio.h>

int main() {
    char families[][2][10] = {
        {"Henrique", "Ivanete"},
        {"Vanessa", "Elaine"}
    };

    int familiesSize = sizeof(families) / sizeof(families[0]);
    printf("familiesSize: %d\n\n", familiesSize);
    // family
    for (int i = 0; i < familiesSize; i++) {
        // family member
        printf("Family %d:\n", i + 1);
        int familySize = sizeof(families[i]) / sizeof(families[i][0]);
        printf("Family size: %d\n", familiesSize);
        for (int j = 0; j < familySize; j++) {
            printf("Member: %s\n", families[i][j]);
        }
        printf("\n");
    }
    return 0;
}