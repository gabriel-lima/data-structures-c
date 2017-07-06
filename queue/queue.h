typedef struct Element
{
    int value;
    struct Element *next;
} Element;

typedef struct Queue
{
    struct Element *rear;
    struct Element *front;
    int length;
} Queue;

Queue *newQueue();
void destroyQueue(Queue *queue);
Element *newElement(int value);
void enqueue(Queue *queue, Element *element);
Element *dequeue(Queue *queue);
