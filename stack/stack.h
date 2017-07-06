typedef struct Element
{
    int value;
    struct Element *next;
} Element;

typedef struct Stack
{
    struct Element *top;
    int length;
} Stack;

Stack *newStack();
void destroyStack(Stack *stack);
Element *newElement(int value);
void push(Stack *stack, Element *element);
Element *pop(Stack *stack);
