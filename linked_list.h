#include <stdbool.h>

typedef struct Node
{
    struct Node *next;
    int value;
} Node;

int length(Node *head);
int *display(Node *head);
bool elementAt(Node *head, int indexToFind, int **value);
void insertInFront(Node **head, int value);
bool deleteInFront(Node **head);
bool deleteByIndex(Node **head, int indexToDelete);
