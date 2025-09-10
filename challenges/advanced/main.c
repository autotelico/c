#include <stdio.h>
#include "11-stack.h"

int main(void) {
	Stack *stack = create_stack();
	char *str = "first string";
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_push(stack, "something cool");
	stack_pop(stack);
	print_values(stack);

	
	return 0;
}
