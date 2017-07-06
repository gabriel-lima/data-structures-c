#include <stdlib.h>
#include <assert.h>
#include "../xunit/runner.h"
#include "queue.h"

static void setUp();
static void tearDown();

static void test_new_queue();

int main()
{
    Runner *runner = init(&setUp, &tearDown);

    registerTest(runner, &test_new_queue);

    run(runner);

    return 0;
}

static void setUp(){}
static void tearDown(){}

static void test_new_queue()
{
    Queue *q = newQueue();

    assert(NULL != q);
    assert(NULL == q->rear);
    assert(NULL == q->front);
    assert(0 == q->length);
}
