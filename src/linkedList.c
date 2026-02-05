#include "../headers/linkedList.h"
#include <errno.h>
#include <stdlib.h>

int
linkedList_create (LinkedList *l)
{
    if (!l) return -EINVAL;

    // Inicializa a lista zerando o size, a alocação do head é feita no insert
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
    return 0;
}

int
linkedList_destroy (LinkedList *l)
{
    if (!l) return -EINVAL;

    l->size = -1;

    while (l->head)
        {
            Node *next = l->head->next;
            free (l->head);
            l->head = next;
        }

    l->head = NULL;
    l->tail = NULL;

    return 0;
}

int
linkedList_is_empty (LinkedList *l, bool *response)
{
    if (!l || !response) return -EINVAL;

    *response = l->size == 0;

    return 0;
}

int
linkedList_insert (LinkedList *l, void *item)
{
    // Valida se os parametros sao validos
    if (!l || !item) return -EINVAL;

    bool listEmpty = true;
    int ret = linkedList_is_empty (l, &listEmpty);

    if (ret != 0) return ret;

    // Se a lista for vazia, adiciona o node como head e tail, com prev/next
    // zerados
    if (listEmpty)
        {
            Node *newNode = malloc (sizeof (Node));
            newNode->value = item;
            newNode->next = NULL;
            newNode->prev = NULL;

            l->head = newNode;
            l->tail = newNode;
        }

    // Se nao for o primeiro elemento, adiciona como proximo e ajusta a tail da
    // lista
    else
        {
            Node *newNode = malloc (sizeof (Node));
            newNode->value = item;
            newNode->next = NULL;
            newNode->prev = l->tail;

            l->tail->next = newNode;

            l->tail = newNode;
        }

    l->size++;

    return 0;
}

int
linkedList_delete (LinkedList *l, const int index)
{
    if (!l || index > l->size || index < 0) return -EINVAL;

    Node *n = l->head;
    int i = 0;

    while (n != NULL && i < index)
        {
            n = n->next;
            i++;
        }

    if (n->prev)
        {
            n->prev->next = n->next ? n->next : NULL;
        }

    if (n->next)
        {
            n->next->prev = n->prev ? n->prev : NULL;
        }

    if (n == l->head)
        {
            l->head = n->next;
        }

    if (n == l->tail)
        {
            l->tail = n->prev;
        }

    free (n);

    l->size--;

    return 0;
}

int
linkedList_search_by_index (LinkedList *l, int index, Node **response)
{
    if (!l || index > l->size || index < 0) return -EINVAL;

    Node *n = l->head;
    int i = 0;

    while (n != NULL && i < index)
        {
            n = n->next;
            i++;
        }

    *response = n;

    return 0;
}
