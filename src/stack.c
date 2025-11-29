#include "../headers/stack.h"
#include <stdio.h>

// nao precisa incluir o bool pois ja esta no header

void stack_create(Stack* s)
{
	if (!s)
	{
		printf("Objeto da pilha inválido.\n");
		return;
	}

	s->top = -1;
}

bool stack_is_empty(Stack *s)
{
	if (!s)
	{
		printf("Objeto da pilha inválido.\n");
		return false;
	}

	if (s->top == -1) return true;

	return false;
}

bool stack_is_full(Stack *s)
{
	if (!s)
	{
		printf("Objeto da pilha inválido.\n");
		return false;
	}

	if (s->top == SIZE - 1) return true;

	return false;
}

void stack_push(Stack* s, int item)
{
	if (!s)
	{
		printf("Objeto da pilha inválido.\n");
		return;
	}
	
	if (stack_is_full(s))
	{
		printf("A pilha está cheia!\n");
		return;
	}

	s->top++;
	s->items[s->top] = item;
}

int stack_pop(Stack *s)
{
	if (!s)
	{
		printf("Objeto da pilha inválido.\n");
		return 0;
	}

	if (stack_is_empty(s))
	{
		printf("A pilha está vazia!\n");
		return 0;
	}

	// retorna o valor do topo e ja diminui o top
	return s->items[s->top--];	
}

int stack_peek(Stack *s)
{
	if (!s)
	{
		printf("Objeto da pilha inválido.\n");
		return 0;
	}

	if (stack_is_empty(s))
	{
		printf("A pilha está vazia!\n");
		return 0;
	}

	// retorna o valor do topo e ja diminui o top
	return s->items[s->top];	
}
