#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int push(int value, Stack *stack) {
	if (stack->size == 50) {
		perror("Cannot push. Stack is full");
		return 1;
	}

	stack->data[stack->size++] = value;
	
	return 0;
}

int pop(Stack *stack) {
	if (stack->size == 0) {
		perror("Cannot pop. Stack is empty");
		return 1;
	}

	stack->size--;

	return 0;
}

int peek(Stack *stack, int *output) {
	if (stack->size == 0) {
		perror("Stack is empty");
		return 1;
	}
	
	*output = stack->data[stack->size - 1];

	return 0;
}
