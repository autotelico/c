#include <stdio.h>

int main(void) {
    int a, b, c, d;
    printf("Enter the two fractions separated by a plus sign: \n");
    scanf("%d/%d+%d/%d", &a, &b, &c, &d);
    printf("%d/%d and %d/%d", a, b, c, d);
    // won't bother about lcd calculation
    return 0;
}