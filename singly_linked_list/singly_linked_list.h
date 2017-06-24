#include <stdbool.h>

typedef struct Node
{
    struct Node *previous;
    struct Node *next;
    int value;
} Node;

typedef struct LinkedList
{
    int length;
    struct Node *first;
} LinkedList;

LinkedList *newLinkedList();
void destroyLinkedList(LinkedList *list);
Node *newNode(int value);
LinkedList *insertNode(LinkedList *list, int value);
Node *elementAt(LinkedList *list, int indexToFind);
LinkedList *removeNode(LinkedList *list);
