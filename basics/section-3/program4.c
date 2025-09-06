#include <stdio.h>

int main(void) {
    int ddi, firstPart, secondPart;
    printf("Enter telephone: \n");
    scanf("(%d) %d-%d", &ddi, &firstPart, &secondPart);
    printf("You entered %.3d.%.3d.%.4d", ddi, firstPart, secondPart);
    
    return 0;
}