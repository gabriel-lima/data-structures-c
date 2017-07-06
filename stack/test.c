#include "../xunit/runner.h"
#include "stack.h"
#include <stdlib.h>
#include <assert.h>

static void setUp();
static void tearDown();

static void test_new_stack();
static void test_new_element();

/* begin tests to push */
static void test_push_one_element();
static void test_push_two_elements();
static void test_push_three_elements();
static void test_doesnt_push_when_stack_is_null();
static void test_doesnt_push_when_element_is_null();
/* end */

/* begin tests to pop */
static void test_push_when_has_one_element();
static void test_push_when_has_two_elements();
static void test_push_when_has_three_elements();
/* end */

/* begin length */
static void test_length_when_push_one_element();
static void test_length_when_push_two_elements();
static void test_length_when_pop_one_element();
static void test_length_when_pop_two_elements();
/* end */

int main()
{
    Runner *runner = init(&setUp, &tearDown);

    registerTest(runner, &test_new_stack);
    registerTest(runner, &test_new_element);

    /* begin tests to push */
    registerTest(runner, &test_push_one_element);
    registerTest(runner, &test_push_two_elements);
    registerTest(runner, &test_push_three_elements);
    registerTest(runner, &test_doesnt_push_when_stack_is_null);
    registerTest(runner, &test_doesnt_push_when_element_is_null);
    /* end */

    /* begin tests to pop */
    registerTest(runner, &test_push_when_has_one_element);
    registerTest(runner, &test_push_when_has_two_elements);
    registerTest(runner, &test_push_when_has_three_elements);
    /* end */

    /* begin length */
    registerTest(runner, &test_length_when_push_one_element);   
    registerTest(runner, &test_length_when_push_two_elements);
    registerTest(runner, &test_length_when_pop_one_element);
    registerTest(runner, &test_length_when_pop_two_elements);
    /* end */

    run(runner);

    return 0;
}

Stack *stack = NULL;
static void setUp()
{
    stack = newStack();
}

static void tearDown()
{
    destroyStack(stack);
}

static void test_new_stack()
{
    Stack *s = newStack();

    assert(NULL != s);
    assert(NULL == s->top);
    assert(0 == stack->length);
}

static void test_new_element()
{
    Element *e = newElement(10);

    assert(NULL != e);
    assert(10 == e->value);
    assert(NULL == e->next);
}

/* begin tests to push */
static void test_push_one_element()
{
    Element *one = newElement(10);

    push(stack, one);

    assert(one == stack->top);
}

static void test_push_two_elements()
{
    Element *one = newElement(10);
    Element *two = newElement(20);

    push(stack, one);
    push(stack, two);

    assert(two == stack->top);
    assert(one == stack->top->next);
}

static void test_push_three_elements()
{
    Element *one = newElement(10);
    Element *two = newElement(20);
    Element *three = newElement(30);

    push(stack, one);
    push(stack, two);
    push(stack, three);

    assert(three == stack->top);
    assert(two == stack->top->next);
    assert(one == stack->top->next->next);
}

static void test_doesnt_push_when_stack_is_null()
{
    Element *one = newElement(10);

    push(NULL, one);

    assert(NULL == stack->top);
}

static void test_doesnt_push_when_element_is_null()
{
    push(stack, NULL);

    assert(NULL == stack->top);
}
/* end */

/* begin tests to pop */
static void test_push_when_has_one_element()
{
    Element *one = newElement(10);
    push(stack, one);

    Element *elementToRemove = pop(stack);

    assert(one == elementToRemove);
    assert(NULL == stack->top);
}

static void test_push_when_has_two_elements()
{
    Element *one = newElement(10);
    push(stack, one);    
    Element *two = newElement(20);
    push(stack, two);

    Element *elementToRemove = pop(stack);

    assert(two == elementToRemove);
    assert(one == stack->top);
}

static void test_push_when_has_three_elements()
{
    Element *one = newElement(10);
    push(stack, one);    
    Element *two = newElement(20);
    push(stack, two);
    Element *three = newElement(30);
    push(stack, three);

    Element *elementToRemove = pop(stack);

    assert(three == elementToRemove);
    assert(two == stack->top);
    assert(one == stack->top->next);
}
/* end */

/* begin length */
static void test_length_when_push_one_element()
{
    push(stack, newElement(10));

    assert(1 == stack->length);
}

static void test_length_when_push_two_elements()
{
    push(stack, newElement(10));    
    push(stack, newElement(20));

    assert(2 == stack->length);
}

static void test_length_when_pop_one_element()
{
    push(stack, newElement(10));
    pop(stack);

    assert(0 == stack->length);
}

static void test_length_when_pop_two_elements()
{
    push(stack, newElement(10));    
    push(stack, newElement(20));
    pop(stack);

    assert(1 == stack->length);
}
/* end */
