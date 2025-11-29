#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#define SIZE 10

typedef struct {
	int items[SIZE];
	int top;
} Stack;

void stack_create(Stack* s);
void stack_push(Stack* s, int item);
int stack_pop(Stack* s);
int stack_peek(Stack* s);
bool stack_is_empty(Stack* s);
bool stack_is_full(Stack* s);

#endif
