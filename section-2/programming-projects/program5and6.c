#include <stdio.h>
#include <math.h>

int calculatePolynomial(int x) {
    return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
}

int calculatePolynomialShortened(int x) {
    return (((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);
}

int main(void) {
    printf("The polynomial calculation result is: %d\n", calculatePolynomial(2));
    printf("The shortened polynomial calculation result is: %d\n", calculatePolynomialShortened(2));
    
    return 0;
}

/* ZERO ChatGPT used, baby! We go old school style */