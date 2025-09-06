#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Stack stack;
	stack.size = 0;
	
	push(1, &stack);
	push(2, &stack);
	push(32, &stack);
	
	int output;
	peek(&stack, &output);
	printf("Peeked number: %d\n", output);

	for (int i = 0; i < stack.size; i++) {
		printf("stack.data[%d] = %d\n", i, stack.data[i]);
	}

	return 0;
}
