/*
 *	Write a function that calculates the length of 
 *	a string without using <string.h> functions
 * */

#include <stdio.h>

int strlen_(char *s) {
	int counter = 0;

	while (s[counter] != '\0') {
		counter++;
	}

	return counter;
}


int main (int argc, char **argv) {
	char *text = "something";
	int textLen = strlen_(text);
	
	printf("strlen = %d\n", textLen);

	return 0;
}
