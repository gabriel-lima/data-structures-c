#include "stack.h"
#include <stdlib.h>

Stack *newStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->length = 0;
    return stack;
}

void destroyStack(Stack *stack)
{
    free(stack);
}

Element *newElement(int value)
{
    Element *element = malloc(sizeof(Element));
    element->value = value;
    element->next = NULL;
    return element;
}

void push(Stack *stack, Element *element)
{
    if (stack == NULL || element == NULL)
        return;
    
    element->next = stack->top;
    stack->top = element;
    stack->length++;
}

Element *pop(Stack *stack)
{
    Element *elementToRemove = stack->top;
    stack->top = stack->top->next;
    stack->length--;
    return elementToRemove;
}
