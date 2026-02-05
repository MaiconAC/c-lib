#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    void *value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
	int size;
} LinkedList;

int linkedList_create(LinkedList *l);
int linkedList_destroy(LinkedList *l);
int linkedList_insert(LinkedList *l, void* item);
int linkedList_is_empty(LinkedList *l, bool *response);
int linkedList_delete(LinkedList *l, const int index);
int linkedList_search_by_index(LinkedList *l, int index, Node **response);

#endif
