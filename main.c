#include "headers/linkedList.h"
#include "headers/queue.h"
#include "headers/stack.h"
#include <stdio.h>
#include <stdlib.h>

void
test_stack ()
{
    Stack *pilha = malloc (sizeof (Stack));
    stack_create (pilha);

    // teste de capacidade
    printf ("capacity inicial: %d\n", pilha->capacity);

    // empilhar mais que capacidade inicial
    for (int i = 0; i < 20; i++)
        {
            int *val = malloc (sizeof (int));
            *val = i;
            int ret = stack_push (pilha, val);
            if (ret != 0)
                {
                    printf ("erro ao empilhar: %d\n", ret);
                    free (val);
                    break;
                }
            printf ("empilhado %d, top=%d, capacity=%d\n", i, pilha->top,
                    pilha->capacity);
        }

    // desempilhar tudo
    bool stack_empty = false;
    stack_is_empty (pilha, &stack_empty);

    while (!stack_empty)
        {
            int *val;
            stack_pop (pilha, (void **)&val);

            printf ("pop: %d\n", *val);
            free (val);
            stack_is_empty (pilha, &stack_empty);
        }

    stack_destroy (pilha);
    free (pilha);
}

void
test_queue ()
{
    Queue *fila = malloc (sizeof (Queue));
    queue_create (fila);

    // teste de capacidade
    printf ("capacity inicial: %d\n", fila->capacity);

    // empilhar mais que capacidade inicial
    for (int i = 0; i < 20; i++)
        {
            int *val = malloc (sizeof (int));
            *val = i;

            int ret = queue_enqueue (fila, val);
            if (ret != 0)
                {
                    printf ("erro ao empilhar: %d\n", ret);
                    free (val);
                    break;
                }

            printf ("enqueue %d, start=%d, end=%d, capacity=%d\n", i,
                    fila->start, fila->end, fila->capacity);
        }

    // desempilhar tudo
    bool queueEmpty = false;
    queue_is_empty (fila, &queueEmpty);

    while (!queueEmpty)
        {
            int *val;
            queue_dequeue (fila, (void **)&val);

            printf ("dequeue: %d\n", *val);
            free (val);
            queue_is_empty (fila, &queueEmpty);
        }

    queue_destroy (fila);
    free (fila);
}

void
test_linked_list ()
{
    LinkedList *linkedList = malloc (sizeof (LinkedList));
    linkedList_create (linkedList);

    for (int i = 0; i < 20; i++)
        {

            int *val = malloc (sizeof (int));
            *val = i;

            int ret = linkedList_insert (linkedList, val);

            if (ret != 0)
                {
                    printf ("erro ao adicionar na fila");
                    free (val);
                }

            int head = *((int *)linkedList->head->value);
            int tail = *((int *)linkedList->tail->value);

            printf ("adicionado na fila, head=%d, tail=%d, size=%d\n", head,
                    tail, linkedList->size);
        }

    Node *n;

    int ret = linkedList_search_by_index (linkedList, 5, &n);

    if (ret != 0)
        {
            printf ("erro ao adicionar na fila");
            free (n);
        }

    printf ("Valor: %d", *((int *)n->value));

    linkedList_delete (linkedList, 5);

    ret = linkedList_search_by_index (linkedList, 5, &n);

    if (ret != 0)
        {
            printf ("erro ao adicionar na fila");
            free (n);
        }

    printf ("Valor: %d", *((int *)n->value));
}

int
main ()
{
    // test_stack();
    // test_queue ();
    test_linked_list ();
    return 0;
}
