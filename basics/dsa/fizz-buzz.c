#include <stdio.h>

void fizzBuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        printf("Fizz Buzz\n");
        return;
    }
    if (n % 3 == 0) {
        printf("Fizz\n");
        return;
    }
    if (n % 5 == 0) {
        printf("Buzz\n");
        return;
    }
    printf("%d\n", n);
}

int main() {
    fizzBuzz(15);
    
    return 0;
}