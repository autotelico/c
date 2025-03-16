#include <stdio.h>
#include <string.h>

int main(void) {
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): \n");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("The date entered is: %.4d%.2d%.2d", year, month, day);

    return 0;
}