#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#define INITIAL_SIZE 2
#define GROWTH_FACTOR 2

/*
 * A pilha não tem ownership dos dados, quem aloca é o responsável por desalocar
 *
 * void** items: itens da pilha, usa ** pois os itens adicionados
 * sao alocados com malloc e só é passado o ponteiro, é um
 * ponteiro de ponteiros
 *
 * int top: index do topo da pilha
 *
 * int capacity: capacidade atual da pilha, cresce 2x sempre que passa a capacidade
 */

typedef struct {
	void** items; // ponteiro de ponteiro, tamanho dinamico
	int top;
	int capacity;
} Stack;

// Se der erro na alocacao inicial da Pilha, nao deixa usar
int stack_create(Stack* s);
int stack_destroy(Stack* s);
int stack_push(Stack* s, void* item);
int stack_pop(Stack* s, void **response);
// uso de const em funcoes que nao mudam a pilha para otimizacao
int stack_peek(const Stack* s, void **response);
int stack_is_empty(const Stack* s, bool *response);
int stack_is_full(const Stack* s, bool *response);
int stack_size(const Stack* s, int *response);

#endif
