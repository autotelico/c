#include <stdio.h>

int sum_digits(int n) {
	int sum = 0;
	int rightDigit = n % 10;
	int leftChunk = n / 10;

	while (leftChunk != 0 || rightDigit != 0) {
		sum = sum + rightDigit;
		rightDigit = leftChunk % 10;
		leftChunk = leftChunk / 10;
	}

	return sum;
}

int sum_digits_rec(int n, int result) {
	int rightDigit = n % 10;
	int leftChunk = n / 10;
	if (rightDigit == 0 && leftChunk == 0) return result;
	int newResult = result + rightDigit;
	return sum_digits_rec(leftChunk, newResult);
}

int main(int argc, char **argv) {
	int number = 123;
	int summed_digits = sum_digits(number);
	int summed_digits_rec = sum_digits_rec(number, 0);

	printf("sum_digits = %d\n", summed_digits);
	printf("sum_digits_rec = %d\n", summed_digits_rec);

	return 0;
}
