#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "singly_linked_list.h"

/* begin: tests to insertNode */
static void test_insert_node_only_one_value(void);
static void test_insert_node_add_value_in_front(void);
static void test_when_just_one_node_set_next_with_null(void);
static void test_when_more_than_one_node_set_next_node(void);
static void test_when_just_one_node_set_previous_with_null(void);
static void test_when_more_than_one_node_set_previous(void);
static void test_when_list_is_null_dont_insert(void);
/* end: tests to insertNode */

/* begin: tests to elementAt */
static void test_return_node_when_index_found(void);
static void test_when_index_doesnt_found_dont_get_node(void);
static void test_when_list_is_null_dont_get_node(void);
/* end: tests to elementAt */

/* begin: removeNode */
static void when_list_is_null_dont_remove(void);
static void when_first_node_is_null_dont_remove(void);
static void when_remove_first_node(void);
/* end: removeNode */

void (*testFunctions[])(void) = {
    test_insert_node_only_one_value,
    test_insert_node_add_value_in_front,
    test_when_just_one_node_set_next_with_null,
    test_when_more_than_one_node_set_next_node,
    test_when_just_one_node_set_previous_with_null,
    test_when_more_than_one_node_set_previous,
    test_when_list_is_null_dont_insert,
    test_return_node_when_index_found,
    test_when_index_doesnt_found_dont_get_node,
    test_when_list_is_null_dont_get_node,
    when_list_is_null_dont_remove,
    when_first_node_is_null_dont_remove,
    when_remove_first_node,
    NULL};

LinkedList *list = NULL;
static void setupUp()
{
    list = newLinkedList();
}

static void tearDown()
{
    destroyLinkedList(list);
}

/* 
to run: 
    gcc -std=c99 -Wall singly_linked_list_test.c singly_linked_list.c -o singly_linked_list_test && ./singly_linked_list_test

to debug:
    gcc -std=c99 -Wall singly_linked_list_test.c singly_linked_list.c -o singly_linked_list_test -g && gdb ./singly_linked_list_test
*/
int main(void)
{
    int current = 0;
    do
    {
        setupUp();

        (*testFunctions[current])();

        tearDown();

        current++;
    } while ((*testFunctions[current]) != NULL);

    return 0;
}

/* begin: tests to insertNode */
static void test_insert_node_only_one_value(void)
{
    list = insertNode(list, 10);

    assert(1 == list->length);
    assert(NULL != list->first);
    assert(10 == list->first->value);
}

static void test_insert_node_add_value_in_front(void)
{
    list = insertNode(list, 10);
    list = insertNode(list, 20);

    assert(2 == list->length);
    assert(NULL != list->first);
    assert(20 == list->first->value);
    assert(NULL != list->first->next);
    assert(10 == list->first->next->value);
}

static void test_when_just_one_node_set_next_with_null(void)
{
    list = insertNode(list, 10);

    assert(1 == list->length);
    assert(NULL != list->first);
    assert(NULL == list->first->next);
}

static void test_when_more_than_one_node_set_next_node(void)
{
    list = insertNode(list, 10);
    list = insertNode(list, 20);

    assert(2 == list->length);
    assert(NULL != list->first);
    assert(NULL != list->first->next);
    assert(NULL == list->first->next->next);
}

static void test_when_just_one_node_set_previous_with_null(void)
{
    list = insertNode(list, 10);

    assert(1 == list->length);
    assert(NULL != list->first);
    assert(NULL == list->first->previous);
}

static void test_when_more_than_one_node_set_previous(void)
{
    list = insertNode(list, 10);
    list = insertNode(list, 20);
    list = insertNode(list, 30);

    assert(3 == list->length);
    assert(NULL != list->first);
    assert(NULL == list->first->previous);
    assert(NULL != list->first->next->previous);
    assert(list->first->next->previous == list->first);
    assert(list->first->next->next->previous == list->first->next);
}

static void test_when_list_is_null_dont_insert(void)
{
    assert(NULL == insertNode(NULL, 10));
}
/* end: tests to insertNode */

/* begin: tests to elementAt */
static void test_return_node_when_index_found(void)
{
    list = insertNode(list, 10);
    list = insertNode(list, 20);

    assert(20 == elementAt(list, 0)->value);
    assert(10 == elementAt(list, 1)->value);
}

static void test_when_index_doesnt_found_dont_get_node(void)
{
    list = insertNode(list, 10);

    assert(NULL == elementAt(list, -1));
}

static void test_when_list_is_null_dont_get_node(void)
{
    list = insertNode(list, 10);

    assert(NULL == elementAt(NULL, 0));
}
/* end: tests to elementAt */

/* begin: removeNode */
static void when_list_is_null_dont_remove(void)
{
    list = insertNode(list, 10);

    assert(NULL == removeNode(NULL));
    assert(1 == list->length);
}

static void when_first_node_is_null_dont_remove(void)
{
    assert(NULL == removeNode(list));
    assert(0 == list->length);
}

static void when_remove_first_node(void)
{
    list = insertNode(list, 10);
    list = insertNode(list, 10);

    list = removeNode(list);

    assert(1 == list->length);
}
/* end: removeNode */
