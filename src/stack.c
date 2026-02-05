#include "../headers/stack.h"
#include <stdlib.h>
#include <errno.h>

// nao precisa incluir o bool pois ja esta no header

int stack_create(Stack* s)
{
	// Erro invalid argument
	if (!s) return -EINVAL;

	s->top = -1;
	s->capacity = INITIAL_SIZE;
	s->items = malloc(s->capacity * sizeof(void*));

	// Erro ao alocar memoria (Out of memory)
	// se nao conseguir inicializar a pilha, deixa ela inutilizável
	if (!s->items)
	{
		s->top = -2;
		s-> items = NULL;
		s->capacity = 0;
		return -ENOMEM;
	}

	return 0;
}

int stack_destroy(Stack *s)
{
	// Erro invalid argument
	if (!s) return -EINVAL;

	// Libera a memoria dos itens e zera a pilha
	free(s->items);
	s->top = -2;
	s->capacity = 0;
	s->items = NULL;

	return 0;
}

int stack_is_empty(const Stack *s, bool *response)
{
	// Erro invalid argument
	if (!s || !response || s->top == -2) return -EINVAL;

	*response = s->top == -1;

	return 0;
}

int stack_is_full(const Stack *s, bool *response)
{
	// Erro invalid argument
	if (!s || !response || s->top == -2) return -EINVAL;

	*response = s->top == s->capacity - 1;

	return 0;
}

// usando void*, a pilha passa a armazenar apenas o edereço do valor
int stack_push(Stack* s, void* item)
{
	// Erro invalid argument
	if (!s || !item || s->top == -2) return -EINVAL;
	
	// Valida se a pilha esta cheia
	bool stack_full = false;
	int ret = stack_is_full(s, &stack_full);

	if (ret != 0) return ret;

	if (stack_full)
	{
		s->capacity = s->capacity * GROWTH_FACTOR;

		void **newPointer = realloc(s->items, s->capacity * sizeof(void *)); 
		
		// Erro ao realocar a pilha (out of memory)
		if (!newPointer) 
		{
			return -ENOMEM;
		}

		// só substitui o ponteiro realocado após ter certeza que não teve erro
		s->items = newPointer;
	}

	// Aumenta o top e adiciona o item
	s->items[++s->top] = item;

	return 0;
}

int stack_pop(Stack *s, void **response)
{
	// Erro invalid argument
	if (!s || !response || s->top == -2) return -EINVAL;

	// Valida se a pilha esta vazia
	bool stack_empty = false;
	int ret = stack_is_empty(s, &stack_empty);

	if (ret != 0) return ret;

	// Erro pilha vazia (No such entry)
	if (stack_empty)
	{
		return -ENOENT;
	}

	// retorna o valor do topo e ja diminui o top
	*response = s->items[s->top--];	

	return 0;
}

int stack_peek(const Stack *s, void **response)
{
	// Erro invalid argument
	if (!s || !response || s->top == -2) return -EINVAL;

	// Valida se a pilha esta vazia
	bool stack_empty = false;
	int ret = stack_is_empty(s, &stack_empty);

	if (ret != 0) return ret;

	// Erro pilha vazia (No such entry)
	if (stack_empty)
	{
		return -ENOENT;
	}

	*response = s->items[s->top];	

	return 0;
}

int stack_size(const Stack *s, int *response)
{
	// Erro invalid argument
	if (!s || !response || s->top == -2) return -EINVAL;

	*response = s->top + 1;

	return 0;
}
