typedef struct Test
{
    struct Test *next;
    void (*func)();
} Test;

typedef struct Runner
{
    struct Test *head;
    void (*setUp)();
    void (*tearDown)();
} Runner;

Runner *init(void (*setUp)(), void (*tearDown)());
void registerTest(Runner *runner, void (*func)());
void run(Runner *runner);
