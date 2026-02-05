#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#define INITIAL_SIZE 2
#define GROWTH_FACTOR 2

typedef struct
{
    void **items;
    int start;
    int end;
    int capacity;
} Queue;

int queue_create (Queue *q);
int queue_destroy (Queue *q);
int queue_is_empty (Queue *q, bool *response);
int queue_is_full (Queue *q, bool *response);
int queue_enqueue (Queue *q, void *item);
int queue_dequeue (Queue *q, void **response);
int queue_size (Queue *q, int *response);
#endif
