#include "runner.h"
#include <stdlib.h>

void nothingToDo() {}

Runner *init(void (*setUp)(), void (*tearDown)())
{
    Runner *r = malloc(sizeof(Runner));
    r->head = NULL;
    r->setUp = (setUp == NULL) ? nothingToDo : setUp;
    r->tearDown = (tearDown == NULL) ? nothingToDo : tearDown;

    return r;
}

void registerTest(Runner *runner, void (*test)(void))
{
    if (runner == NULL || test == NULL)
        return;

    Test *t = malloc(sizeof(Test));
    t->func = test;
    t->next = runner->head;

    runner->head = t;
}

void run(Runner *runner)
{
    for (Test *test = runner->head;
         test != NULL;
         test = test->next)
    {
        (*runner->setUp)();
        (*test->func)();
        (*runner->tearDown)();
    }
}
