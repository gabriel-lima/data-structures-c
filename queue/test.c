#include <stdlib.h>
#include <assert.h>
#include "../xunit/runner.h"
#include "queue.h"

static void setUp();
static void tearDown();

static void test_new_queue();
static void test_new_element();

/* begin tests to enqueue */
static void test_enqueue_one_element();
static void test_enqueue_two_elements();
static void test_enqueue_three_elements();
static void test_doesnt_enqueue_when_queue_is_null();
static void test_doesnt_enqueue_when_element_is_null();
static void test_increment_length();
/* end */

/* begin tests to dequeue */
static void test_dequeue_one_element();
static void test_dequeue_two_elements();
static void test_dequeue_three_elements();
static void test_doesnt_dequeue_when_empty();
static void test_decrement_length();
static void test_doesnt_decrement_length_when_hasnt_element();
/* end */

int main()
{
    Runner *runner = init(&setUp, &tearDown);

    registerTest(runner, &test_new_queue);
    registerTest(runner, &test_new_element);

    /* begin tests to enqueue */
    registerTest(runner, &test_enqueue_one_element);
    registerTest(runner, &test_enqueue_two_elements);
    registerTest(runner, &test_enqueue_three_elements);
    registerTest(runner, &test_doesnt_enqueue_when_queue_is_null);
    registerTest(runner, &test_doesnt_enqueue_when_element_is_null);
    registerTest(runner, &test_increment_length);
    /* end */

    /* begin tests to dequeue */
    registerTest(runner, &test_dequeue_one_element);
    registerTest(runner, &test_dequeue_two_elements);
    registerTest(runner, &test_dequeue_three_elements);
    registerTest(runner, &test_doesnt_dequeue_when_empty);
    registerTest(runner, &test_decrement_length);
    registerTest(runner, &test_doesnt_decrement_length_when_hasnt_element);
    /* end */

    run(runner);

    return 0;
}

Queue *queue = NULL;
static void setUp()
{
    queue = newQueue();
}

static void tearDown()
{
    destroyQueue(queue);
}

static void test_new_queue()
{
    Queue *q = newQueue();

    assert(NULL != q);
    assert(NULL == q->rear);
    assert(NULL == q->front);
    assert(0 == q->length);
}

static void test_new_element()
{
    Element *e = newElement(10);

    assert(NULL != e);
    assert(10 == e->value);
    assert(NULL == e->next);
    assert(NULL == e->previous);
}

/* begin tests to enqueue */
static void test_enqueue_one_element()
{
    Element *one = newElement(10);

    enqueue(queue, one);

    assert(one == queue->rear);
    assert(NULL == queue->rear->previous);
    assert(NULL == queue->rear->next);

    assert(one == queue->front);
    assert(NULL == queue->front->previous);
    assert(NULL == queue->front->next);
}

static void test_enqueue_two_elements()
{
    Element *one = newElement(10);
    Element *two = newElement(20);

    enqueue(queue, one);
    enqueue(queue, two);

    assert(two == queue->rear);
    assert(NULL == queue->rear->previous);
    assert(one == queue->rear->next);

    assert(one == queue->front);
    assert(two == queue->front->previous);
    assert(NULL == queue->front->next);
}

static void test_enqueue_three_elements()
{
    Element *one = newElement(10);
    Element *two = newElement(20);
    Element *three = newElement(30);

    enqueue(queue, one);
    enqueue(queue, two);
    enqueue(queue, three);

    assert(three == queue->rear);
    assert(NULL == queue->rear->previous);

    assert(two == queue->rear->next);
    assert(three == queue->rear->next->previous);
    assert(one == queue->rear->next->next);

    assert(one == queue->front);
    assert(two == queue->front->previous);
    assert(NULL == queue->front->next);
}

static void test_doesnt_enqueue_when_queue_is_null()
{
    enqueue(NULL, newElement(10));

    assert(NULL == queue->rear);
    assert(NULL == queue->front);
}

static void test_doesnt_enqueue_when_element_is_null()
{
    enqueue(queue, NULL);

    assert(NULL == queue->rear);
    assert(NULL == queue->front);
}

static void test_increment_length()
{
    enqueue(queue, newElement(10));

    assert(1 == queue->length);
}
/* end */

/* begin tests to dequeue */
static void test_dequeue_one_element()
{
    Element *one = newElement(10);
    enqueue(queue, one);

    Element *elementObtained = dequeue(queue);

    assert(one == elementObtained);
    assert(NULL == queue->rear);
    assert(NULL == queue->front);
}
static void test_dequeue_two_elements()
{
    Element *one = newElement(10);
    Element *two = newElement(20);
    enqueue(queue, one);
    enqueue(queue, two);

    Element *elementObtained = dequeue(queue);

    assert(one == elementObtained);

    assert(two == queue->front);
    assert(NULL == queue->front->next);
    assert(NULL == queue->front->previous);

    assert(two == queue->rear);
    assert(NULL == queue->rear->next);
    assert(NULL == queue->rear->previous);
}
static void test_dequeue_three_elements()
{
    Element *one = newElement(10);
    enqueue(queue, one);
    Element *two = newElement(20);
    enqueue(queue, two);    
    Element *three = newElement(30);
    enqueue(queue, three);

    Element *elementObtained = dequeue(queue);

    assert(one == elementObtained);

    assert(two == queue->front);
    assert(NULL == queue->front->next);
    assert(three == queue->front->previous);

    assert(three == queue->rear);
    assert(two == queue->rear->next);
    assert(NULL == queue->rear->previous);
}

static void test_doesnt_dequeue_when_empty()
{
    Element *elementObtained = dequeue(queue);

    assert(NULL == elementObtained);
    assert(NULL == queue->rear);
    assert(NULL == queue->front);
}

static void test_decrement_length()
{
    enqueue(queue, newElement(10));
    dequeue(queue);

    assert(0 == queue->length);
}

static void test_doesnt_decrement_length_when_hasnt_element()
{
    dequeue(queue);

    assert(0 == queue->length);
}
/* end */
