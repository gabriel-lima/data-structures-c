#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include <stdio.h>

int length(Node *head)
{
    int size = 0;
    for (Node *current = head;
         current != NULL;
         current = current->next)
    {
        size++;
    }
    return size;
}

int *display(Node *head)
{
    int size = length(head);
    int *output = malloc(size * sizeof(int));
    int index = 0;

    for (Node *current = head;
         current != NULL;
         current = current->next, index++)
    {
        output[index] = current->value;
    }

    return output;
}

bool elementAt(Node *head, int indexToFind, int **value)
{
    int index = 0;
    for (Node *current = head; current != NULL; current = current->next, index++)
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

void insertInFront(Node **head, int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;

    *head = newNode;
}

bool deleteInFront(Node **head)
{
    if (*head == NULL)
        return false;

    Node *first = *head;

    *head = first->next;

    free(first);
    first = NULL;

    return true;
}

bool deleteByIndex(Node **head, int indexToDelete)
{
    int index = 0;
    bool found = false;
    Node *previous = NULL;
    Node *current = *head;

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