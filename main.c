#include <stdio.h>
#include "headers/stack.h"

int main()
{
	Stack pilha;
	stack_create(&pilha);

	stack_push(&pilha, 10);
	stack_push(&pilha, 15);
	stack_push(&pilha, 20);
	stack_push(&pilha, 25);

	printf("Stack pop: %d\n", stack_pop(&pilha));
	printf("Stack peek: %d\n", stack_pop(&pilha));

	return 0;
}
