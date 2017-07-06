#include <stdlib.h>
#include "queue.h"

Queue *newQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->rear = NULL;
    q->front = NULL;
    q->length = 0;
    return q;
}

void destroyQueue(Queue *queue)
{
    free(queue);
}

Element *newElement(int value)
{
    Element *e = malloc(sizeof(Element));
    e->value = value;
    e->next = NULL;
    return e;
}
