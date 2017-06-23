#include <stdbool.h>

typedef struct SinglyLinkedList
{
    struct SinglyLinkedList *next;
    int value;
} SinglyLinkedList;

int length(SinglyLinkedList *head);
int *display(SinglyLinkedList *head);
bool elementAt(SinglyLinkedList *head, int indexToFind, int **value);
void insertInFront(SinglyLinkedList **head, int value);
bool deleteInFront(SinglyLinkedList **head);
bool deleteByIndex(SinglyLinkedList **head, int indexToDelete);
