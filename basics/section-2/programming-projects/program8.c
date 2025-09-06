#include <stdio.h>
#define MONTHS 3

float calculateLoan(float amount, float interest, float monthlyPayment) {
    interest = interest / 100;
    
    for (int i = 0; i < MONTHS; i++) {
        amount += amount * interest / 12;
        amount -= monthlyPayment;
        printf("Month 1: %.2f\n", amount);
    }

    return amount;
}

int main(void) {
    int amount = calculateLoan(20000.0, 6.0, 386.66);

    return 0;
}