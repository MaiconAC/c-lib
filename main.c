#include <stdio.h>
#include <stdlib.h>
#include "headers/stack.h"

void test_stack()
{
    Stack *pilha = malloc(sizeof(Stack));
    stack_create(pilha);
    
    // teste de capacidade
    printf("capacity inicial: %d\n", pilha->capacity);
    
    // empilhar mais que capacidade inicial
    for (int i = 0; i < 20; i++) {
        int *val = malloc(sizeof(int));
        *val = i;
        int ret = stack_push(pilha, val);
        if (ret != 0) {
            printf("erro ao empilhar: %d\n", ret);
            free(val);
            break;
        }
        printf("empilhado %d, top=%d, capacity=%d\n", 
               i, pilha->top, pilha->capacity);
    }
    
    // desempilhar tudo
	bool stack_empty = false;
	stack_is_empty(pilha, &stack_empty);

    while (!stack_empty) {
        int *val;
		stack_pop(pilha, (void **)&val);

        printf("pop: %d\n", *val);
        free(val);
		stack_is_empty(pilha, &stack_empty);
    }
    
    stack_destroy(pilha);
    free(pilha);
}

void test_list()
{

}

int main() {
	// test_stack();
	test_list();
    return 0;
}
