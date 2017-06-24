#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "singly_linked_list.h"

/* begin tests to newNode */
static void test_new_node(void);
/* end tests to newNode */

/* begin: tests to insertNode */
static void test_insert_node_only_one_value(void);
static void test_insert_node_add_last_node_in_front(void);
static void test_when_just_one_node_set_next_with_null(void);
static void test_when_more_than_one_node_set_next_node(void);
static void test_when_just_one_node_set_previous_with_null(void);
static void test_when_more_than_one_node_set_previous(void);
static void test_when_list_is_null_dont_insert(void);
static void test_when_node_is_null_dont_insert(void);
/* end: tests to insertNode */

/* begin: tests to elementAt */
static void test_return_node_when_index_found(void);
static void test_when_index_doesnt_found_dont_get_node(void);
static void test_when_list_is_null_dont_get_node(void);
/* end: tests to elementAt */

/* begin: removeNode */
static void when_list_is_null_dont_remove(void);
static void when_first_node_is_null_dont_remove(void);
static void when_remove_change_length(void);
static void set_first_null_when_remove_a_list_just_one_node(void);
static void set_next_when_remove_a_node(void);
static void set_previous_when_remove_a_node(void);
static void when_remove_first_node(void);
/* end: removeNode */

void (*testFunctions[])(void) = {
    test_new_node,
    test_insert_node_only_one_value,
    test_insert_node_add_last_node_in_front,
    test_when_just_one_node_set_next_with_null,
    test_when_more_than_one_node_set_next_node,
    test_when_just_one_node_set_previous_with_null,
    test_when_more_than_one_node_set_previous,
    test_when_list_is_null_dont_insert,
    test_when_node_is_null_dont_insert,
    test_return_node_when_index_found,
    test_when_index_doesnt_found_dont_get_node,
    test_when_list_is_null_dont_get_node,
    when_list_is_null_dont_remove,
    when_first_node_is_null_dont_remove,
    when_remove_change_length,
    set_first_null_when_remove_a_list_just_one_node,
    set_next_when_remove_a_node,
    set_previous_when_remove_a_node,
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

/* begin tests to newNode */
static void test_new_node(void)
{
    Node *node = newNode(10);

    assert(NULL != node);
    assert(10 == node->value);
    assert(NULL == node->previous);
    assert(NULL == node->next);
}
/* end tests to newNode */

/* begin: tests to insertNode */
static void test_insert_node_only_one_value(void)
{
    Node *node = newNode(10);

    bool success = insertNode(list, node);

    assert(true == success);
    assert(1 == list->length);
    assert(NULL != list->first);
    assert(10 == list->first->value);
    assert(node == list->first);
}

static void test_insert_node_add_last_node_in_front(void)
{
    Node *firstNodeAdded = newNode(10);
    Node *lastNodeAdded = newNode(20);

    insertNode(list, firstNodeAdded);
    insertNode(list, lastNodeAdded);

    assert(2 == list->length);
    assert(NULL != list->first);
    assert(lastNodeAdded == list->first);
    assert(lastNodeAdded->value == list->first->value);
    assert(NULL != list->first->next);
    assert(firstNodeAdded == list->first->next);
    assert(firstNodeAdded->value == list->first->next->value);
}

static void test_when_just_one_node_set_next_with_null(void)
{
    Node *node = newNode(10);

    insertNode(list, node);

    assert(1 == list->length);
    assert(NULL != list->first);
    assert(NULL == list->first->next);
}

static void test_when_more_than_one_node_set_next_node(void)
{
    Node *firstNodeAdded = newNode(10);
    Node *lastNodeAdded = newNode(20);

    insertNode(list, firstNodeAdded);
    insertNode(list, lastNodeAdded);

    assert(2 == list->length);
    assert(NULL != list->first);
    assert(NULL != list->first->next);
    assert(NULL == list->first->next->next);
}

static void test_when_just_one_node_set_previous_with_null(void)
{
    Node *node = newNode(10);

    insertNode(list, node);

    assert(1 == list->length);
    assert(NULL != list->first);
    assert(NULL == list->first->previous);
}

static void test_when_more_than_one_node_set_previous(void)
{
    Node *node10 = newNode(10);
    Node *node20 = newNode(20);
    Node *node30 = newNode(30);

    insertNode(list, node10);
    insertNode(list, node20);
    insertNode(list, node30);

    assert(3 == list->length);

    assert(NULL != list->first);
    assert(node30 == list->first);
    assert(NULL == node30->previous);

    assert(NULL != list->first->next);
    assert(node20 == list->first->next);
    assert(node30 == node20->previous);

    assert(NULL != list->first->next->next);
    assert(node10 == list->first->next->next);
    assert(node20 == node10->previous);
}

static void test_when_list_is_null_dont_insert(void)
{
    Node *node = newNode(10);

    bool success = insertNode(NULL, node);

    assert(false == success);
}

static void test_when_node_is_null_dont_insert(void)
{
    bool success = insertNode(list, NULL);

    assert(false == success);
}
/* end: tests to insertNode */

/* begin: tests to elementAt */
static void test_return_node_when_index_found(void)
{
    Node *node10 = newNode(10);
    Node *node20 = newNode(20);
    insertNode(list, node10);
    insertNode(list, node20);

    assert(node20 == elementAt(list, 0));
    assert(node10 == elementAt(list, 1));
}

static void test_when_index_doesnt_found_dont_get_node(void)
{
    Node *node = newNode(10);
    insertNode(list, node);

    assert(NULL == elementAt(list, -1));
}

static void test_when_list_is_null_dont_get_node(void)
{
    Node *node = newNode(10);
    insertNode(list, node);

    assert(NULL == elementAt(NULL, 0));
}
/* end: tests to elementAt */

/* begin: removeNode */
static void when_list_is_null_dont_remove(void)
{
    Node *node = newNode(10);
    insertNode(list, node);

    bool success = removeNode(NULL);

    assert(false == success);
    assert(1 == list->length);
}

static void when_first_node_is_null_dont_remove(void)
{
    bool success = removeNode(list);

    assert(false == success);
    assert(0 == list->length);
}

static void when_remove_change_length(void)
{
    Node *node10 = newNode(10);
    insertNode(list, node10);

    removeNode(list);

    assert(0 == list->length);
}

static void set_first_null_when_remove_a_list_just_one_node(void)
{
    Node *node10 = newNode(10);
    insertNode(list, node10);

    removeNode(list);

    assert(NULL == list->first);
}

static void set_next_when_remove_a_node(void)
{
    Node *node10 = newNode(10);
    Node *node20 = newNode(20);
    Node *node30 = newNode(30);
    insertNode(list, node10);
    insertNode(list, node20);
    insertNode(list, node30);

    removeNode(list);

    assert(node20 == list->first);
    assert(node10 == node20->next);
    assert(node10 == list->first->next);
    assert(NULL == node10->next);
}

static void set_previous_when_remove_a_node(void)
{
    Node *node10 = newNode(10);
    Node *node20 = newNode(20);
    Node *node30 = newNode(30);
    insertNode(list, node10);
    insertNode(list, node20);
    insertNode(list, node30);

    removeNode(list);

    assert(node20 == list->first);
    assert(NULL == node20->previous);
    assert(node10 == list->first->next);
    assert(node20 == node10->previous);
}

static void when_remove_first_node(void)
{
    Node *node10 = newNode(10);
    Node *node20 = newNode(20);
    insertNode(list, node10);
    insertNode(list, node20);

    removeNode(list);

    assert(1 == list->length);
    assert(node10 == list->first);
    assert(NULL == list->first->next);
    assert(NULL == list->first->previous);
}
/* end: removeNode */
