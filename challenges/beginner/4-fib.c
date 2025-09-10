#include <stdio.h>

void fib_iter(int n) {
	if (n <= 0) {
		fprintf(stderr, "Cannot print negative values!");
		return;
	}

	int prev = 0, curr = 1, next, counter = 1;

	printf("The number in position %d is %d\n", counter, prev);
	next = prev + curr;
	counter++;

	while (counter < n) {
		printf("The number in position %d is %d\n", counter, curr);
		next = prev + curr;
		prev = curr;
		curr = next;
		counter++;
	}
}

int fib_rec(int n) {
	if (n < 2) return n;

	return fib_rec(n - 1) + fib_rec(n - 2);
}

int main(int argc, char **argv) {
	int number = 8;
	fib_iter(number);

	for (int i = 0; i < number; i++) {
		printf("fib #%d = %d\n", i + 1, fib_rec(i));
	}
	
	return 0;
}
