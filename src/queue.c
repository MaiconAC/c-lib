#include "../headers/queue.h"
#include <errno.h>
#include <stdlib.h>

int
queue_create (Queue *q)
{
    // Invalid argument se nao for passado um ponteiro valido
    if (!q) return -EINVAL;

    // Inicializa vazio e aloca espaco default inicial
    q->start = 0;
    q->end = -1;
    q->capacity = INITIAL_SIZE;
    q->items = malloc (q->capacity * sizeof (void *));

    // Caso de erro ao alocar a memoria, torna a pilha inutilizavel
    if (!q->items)
        {
            q->capacity = 0;
            q->items = NULL;

            return -ENOMEM;
        }

    return 0;
}

int
queue_destroy (Queue *q)
{
    // Invalid argument se nao for passado um ponteiro valido
    if (!q) return -EINVAL;

    // Libera memória dos itens da fila e deixa ela inutilizavel, precisando
    // dar um queue_create para funcionar
    free (q->items);

    q->capacity = 0;
    q->items = NULL;

    return 0;
}

int
queue_is_empty (Queue *q, bool *response)
{
    // Erro invalid argument
    if (!q || !response || q->items == NULL) return -EINVAL;

    *response = q->end < q-> start;
    return 0;
}

int
queue_is_full (Queue *q, bool *response)
{
    if (!q || !response || q->items == NULL) return -EINVAL;

    *response = q->end - q->start == q->capacity;
    return 0;
}

int
queue_enqueue (Queue *q, void *item)
{
    if (!q || !item || q->items == NULL) return -EINVAL;

    // Valida se a fila esta cheia
    bool queueFull = false;
    int ret = queue_is_full (q, &queueFull);

    if (ret != 0) return ret;

    if (queueFull)
        {
            q->capacity = q->capacity * GROWTH_FACTOR;

            // Realoca a pilha em um novo espaco na memoria com capacidade
            // maior
            void **newPointer
                = realloc (q->items, q->capacity * sizeof (void *));

            // Erro ao realocar a pilha (Out of memory)
            if (!newPointer) return -ENOMEM;

            // Apos ter certeza que nao deu erro, substitui os dados
            q->items = newPointer;
        }

    q->items[++q->end] = item;
    return 0;
}

int
queue_dequeue (Queue *q, void **response)
{
    if (!q || !response || q->items == NULL) return -EINVAL;

    bool queueEmpty = false;
    int ret = queue_is_empty (q, &queueEmpty);

    if (ret != 0) return ret;

    if (queueEmpty) return -ENOENT;

    *response = q->items[q->start++];
    return 0;
}

int
queue_size (Queue *q, int *response)
{
    if (!q || !response || q->items == NULL) return -EINVAL;

    *response = q->end - q->start + 1;
    return 0;
}
