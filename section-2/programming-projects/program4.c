#include <stdio.h>

float amountWithTax(float amount, float tax) {
    return amount + (amount * tax / 100.0f);
}

int main(void) {
    float originalAmount = 100.0f;
    float tax = 5.0f;
    float result = amountWithTax(originalAmount, tax);
    printf("Original amount: %.2f\n", originalAmount);
    printf("Amount w/ added tax: %.2f\n", result);
    
    return 0;
}