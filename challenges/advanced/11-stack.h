#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef struct Stack Stack;

Stack *create_stack();
void stack_push(Stack *stack, char *s);
char *stack_pop(Stack *stack);
void print_values(Stack *stack);


#endif
