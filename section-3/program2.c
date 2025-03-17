#include <stdio.h>

int main(void) {
    int itemNumber, pDay, pMonth, pYear;
    float price;
    printf("Enter item number: \n");
    scanf("%d", &itemNumber);
    printf("Enter unit price: \n");
    scanf("%f", &price);
    printf("Enter purchase date: \n");
    scanf("%d/%d/%d", &pMonth, &pDay, &pYear);

    printf("Item\tUnit Price\tPurchase Date\n");
    printf("%-5d\t$%4.2f\t%.2d/%.2d/%.4d\n", itemNumber, price, pDay, pMonth, pYear);
    
    return 0;
}