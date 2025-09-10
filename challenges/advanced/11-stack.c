/*
 * I have previously implemented a stack, but
 * since ChatGPT suggested this challenge again, I will
 * take the opportunity to build everything from scratch
 * from the top of my head.
 * 
 * Because it's fun! :)
*/

#include <stdio.h>
#include <stdlib.h>

/* 
 * I'll go with a dynamic char * stack, so
 * it is different from my first stack (int *).
 * */
typedef struct {
	char **values;
	int capacity;
	int size;
} Stack;

Stack *create_stack() {
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->capacity = 16;
	stack->size = 0;
	stack->values = (char **) malloc(sizeof(char *) * stack->capacity);
	

	return stack;
}

void stack_push(Stack *stack, char *s) {
	if (stack->size + 1 > stack->capacity) {
		printf("Reallocating memory for extra capacity\n");

		int new_capacity = stack->capacity * 2;

		char **temp = realloc(stack->values, sizeof(char *) * new_capacity);

		if (temp == NULL) {
			perror("Failed reallocating memory for stack\n");
			return;
		}
		
		stack->values = temp;
		
		printf("New stack capacity is %d\n", stack->capacity);
	}
	stack->values[stack->size++] = s;
}

char *stack_pop(Stack *stack) {
	if (stack->size == 0) {
		perror("Cannot pop from empty stack\n");
		return NULL;
	}
	
	char *removed_string = stack->values[stack->size--];
	return removed_string;
}

void print_values(Stack *stack) {
	if (stack->size == 0) {
		printf("Stack size is 0. Nothing to print.\n");
		return;
	}
	for (int i = 0; i < stack->size; i++) {
		printf("Index %d: %s\n", i + 1, stack->values[stack->size - 1]);
	}
}
