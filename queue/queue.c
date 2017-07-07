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
    e->previous = NULL;
    return e;
}

void enqueue(Queue *queue, Element *element)
{
    if (!queue || !element)
        return;

    if (!queue->front)
        queue->front = element;

    if (queue->rear)
        queue->rear->previous = element;

    element->next = queue->rear;
    queue->rear = element;
    queue->length++;
}

Element *dequeue(Queue *queue)
{
    Element *elementObtained = queue->front;

    Element *newFront = NULL;
    if (queue->front)
        newFront = queue->front->previous;

    if (newFront)
        newFront->next = NULL;
    else
        queue->rear = NULL;
    
    queue->front = newFront;
    
    if (elementObtained)
        queue->length--;

    return elementObtained;
}
