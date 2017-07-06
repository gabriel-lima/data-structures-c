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