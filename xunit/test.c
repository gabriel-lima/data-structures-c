#include "runner.h"
#include <assert.h>

int setUpCalled = 0;
void setUp();
int tearDownCalled = 0;
void tearDown();
int firstTestFunctionCalled = 0;
void registeredFirstTestFunction();
int secondTestFunctionCalled = 0;
void registeredSecondTestFunction();

void test_xunit(void);
int main(void)
{
    test_xunit();
}

void test_xunit(void)
{
    Runner *r = init(&setUp, &tearDown);
    
    registerTest(r, &registeredFirstTestFunction);
    registerTest(r, &registeredSecondTestFunction);

    run(r);

    assert(1 == firstTestFunctionCalled);
    assert(1 == secondTestFunctionCalled);
    assert(2 == setUpCalled);
    assert(2 == tearDownCalled);
}

void setUp()
{
    setUpCalled++;
}

void tearDown()
{
    tearDownCalled++;
}

void registeredFirstTestFunction(void)
{
    firstTestFunctionCalled++;
}

void registeredSecondTestFunction(void)
{
    secondTestFunctionCalled++;
}
