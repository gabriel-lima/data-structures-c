#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"

LinkedList *newLinkedList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->length = 0;
    list->first = NULL;

    return list;
}

void destroyLinkedList(LinkedList *list)
{
    free(list);
}

LinkedList *insertNode(LinkedList *list, int value)
{
    if (list == NULL)
        return NULL;

    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->previous = NULL;
    new->next = list->first;

    if (list->first != NULL)
        list->first->previous = new;

    list->first = new;
    list->length++;

    return list;
}

LinkedList *removeNode(LinkedList *list)
{
    if (list == NULL || list->first == NULL)
        return NULL;

    Node *afterFirst = list->first->next;
    free(list->first);
    list->first = afterFirst;

    list->length--;

    return list;
}

Node *elementAt(LinkedList *list, int indexToFind)
{
    if (list == NULL)
        return NULL;

    int index = 0;
    Node *current = NULL;
    for (current = list->first; current != NULL; current = current->next, index++)
    {
        if (index == indexToFind)
            return current;
    }
    return current;
}
