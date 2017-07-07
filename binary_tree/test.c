#include <stdlib.h>
#include "binary_tree.h"
#include "../xunit/runner.h"
#include <assert.h>

static void setUp();
static void tearDown();

int main()
{
    Runner *runner = init(&setUp, &tearDown);

    run(runner);
    return 0;
}

static void setUp(){}
static void tearDown(){}