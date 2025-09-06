#include <stdio.h>

int main(void) {
    int gsi, groupId, pubCode, itemNumber, checkDigit;
    printf("Enter ISBN: \n");
    scanf("%d-%d-%d-%d-%d", &gsi, &groupId, &pubCode, &itemNumber, &checkDigit);
    printf("GSI prefix: %3d\n", gsi);
    printf("Group Identifier: %d\n", groupId);
    printf("Publisher code: %3d\n", pubCode);
    printf("Item number: %5d\n", itemNumber);
    printf("Check digit: %d\n", checkDigit);
    
    return 0;
}