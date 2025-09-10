#include <stdio.h>
#include <stdlib.h>

int calculate(int a, char op, int b) {

	switch(op) {
		case '+':
				return a + b;
		case '-':
				return a - b;
		case '/':
				if (b == 0) {
					perror("Cannot divide by zero");
					exit(1);
				}
				return a / b;
		case '*':
				return a * b;
		default:
				perror("Invalid operator");
				exit(1);
	}
}

int main(int argc, char **argv) {
	int a = 50, b = 10;
	printf("calculate = %d\n", calculate(a, '/', b));

	return 0;
}
