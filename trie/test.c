#include <stdlib.h>
#include "../xunit/runner.h"
#include <assert.h>
#include "trie.h"

static void setUp();
static void tearDown();

int main()
{
    Runner *r = init(&setUp, &tearDown);
    run(r);

    return 0;
}

static void setUp(){}
static void tearDown(){}
