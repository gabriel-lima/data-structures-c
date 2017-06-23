#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"

int length(SinglyLinkedList *head)
{
    int size = 0;
    for (SinglyLinkedList *current = head;
         current != NULL;
         current = current->next)
    {
        size++;
    }
    return size;
}

int *display(SinglyLinkedList *head)
{
    int size = length(head);
    int *output = malloc(size * sizeof(int));
    int index = 0;

    for (SinglyLinkedList *current = head;
         current != NULL;
         current = current->next, index++)
    {
        output[index] = current->value;
    }

    return output;
}

bool elementAt(SinglyLinkedList *head, int indexToFind, int **value)
{
    int index = 0;
    for (SinglyLinkedList *current = head;
         current != NULL;
         current = current->next, index++)
    {
        if (index == indexToFind)
        {
            *value = (int *)malloc(sizeof(int));
            *(*value) = current->value;
            return true;
        }
    }
    return false;
}

void insertInFront(SinglyLinkedList **head, int value)
{
    SinglyLinkedList *newNode = malloc(sizeof(SinglyLinkedList));
    newNode->value = value;
    newNode->next = *head;

    *head = newNode;
}

bool deleteInFront(SinglyLinkedList **head)
{
    if (*head == NULL)
        return false;

    SinglyLinkedList *first = *head;

    *head = first->next;

    free(first);
    first = NULL;

    return true;
}

bool deleteByIndex(SinglyLinkedList **head, int indexToDelete)
{
    int index = 0;
    bool found = false;
    SinglyLinkedList *previous = NULL;
    SinglyLinkedList *current = *head;

    while (current != NULL)
    {
        if (index == indexToDelete)
        {
            found = true;
            break;
        }

        previous = current;
        current = current->next;
        index++;
    }

    if (!found)
        return false;

    if (index == 0)
        *head = current->next;
    else
        previous->next = current->next;

    free(current);
    current = NULL;

    return true;
}