#include "../headers/queue.h"
#include <stdlib.h>
#include <errno.h>

int queue_create(Queue *q)
{
	if (!q) return -EINVAL;

	q->start = -1;
	q->end = -1;
	q->capacity = INITIAL_SIZE;
	q->items = malloc(q->capacity * sizeof(void*));

	// Caso de erro ao alocar a memoria, torna a pilha inutilizavel
	if (!q->items)
	{
		q->start = -2;
		q->end = -2;
		q->capacity = 0;
		q->items = NULL;

		return -ENOMEM;
	}

	return 0;
}

int queue_destroy(Queue *q)
{
	if (!q) return -EINVAL;

	free(q->items);

	q->start = -2;
	q->end = -2;
	q->capacity = 0;
	q->items = NULL;

	return 0;
}

int queue_enqueue(Queue *q, void *item)
{
	
}
