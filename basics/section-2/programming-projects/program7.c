#include <stdio.h>

void calculateBills() {
  int dollarAmount;
  printf("Enter a dollar amount: \n");
  scanf("%d", &dollarAmount);
  printf("$20 bills: %d\n", dollarAmount / 20);
  dollarAmount = dollarAmount - (dollarAmount / 20) * 20;
  printf("$10 bills: %d\n", dollarAmount / 10) ;
  dollarAmount = dollarAmount - (dollarAmount / 10) * 10;
  printf("$5 bills: %d\n", dollarAmount / 5);
  dollarAmount = dollarAmount - (dollarAmount / 5) * 5;
  printf("$1 bills: %d\n", dollarAmount / 1);
  dollarAmount = dollarAmount - (dollarAmount / 1);
}

int main(void) {
  calculateBills();
  return 0;
}