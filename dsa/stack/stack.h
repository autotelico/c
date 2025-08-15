#ifndef STACK_H
#define STACK_H

typedef struct {
	int data[50];
	int size;
} Stack;

int push(int value, Stack *stack);
int pop(Stack *stack);
int peek(Stack *stack, int *output);
#endif
