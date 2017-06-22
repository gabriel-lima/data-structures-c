#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "linked_list.h"

static void test_display_values(void);
static void test_display_when_is_empty(void);

static void test_element_at_return_value_by_index(void);
static void test_element_at_when_index_not_found(void);
static void test_element_at_when_list_is_null(void);

static void test_insert_one_value(void);
static void test_insert_value_in_front(void);

static void test_delete_the_first_node(void);
static void test_delete_when_list_is_null(void);

static void test_delete_last_node_by_index(void);
static void test_delete_first_node_by_index(void);
static void test_delete_when_index_not_found(void);
static void test_delete_by_index_when_list_is_null(void);

Node *head = NULL;

// to run: gcc -std=c99 -Wall linked_list_test.c linked_list.c -o linked_list_test && ./linked_list_test
int main(void)
{
    test_display_values();
    free(head);
    head = NULL;
    test_display_when_is_empty();
    free(head);
    head = NULL;

    test_element_at_return_value_by_index();
    free(head);
    head = NULL;
    test_element_at_when_index_not_found();
    free(head);
    head = NULL;
    test_element_at_when_list_is_null();
    free(head);
    head = NULL;

    test_insert_one_value();
    free(head);
    head = NULL;
    test_insert_value_in_front();
    free(head);
    head = NULL;

    test_delete_the_first_node();
    free(head);
    head = NULL;
    test_delete_when_list_is_null();
    free(head);
    head = NULL;

    test_delete_last_node_by_index();
    free(head);
    head = NULL;
    test_delete_first_node_by_index();
    free(head);
    head = NULL;
    test_delete_when_index_not_found();
    free(head);
    head = NULL;
    test_delete_by_index_when_list_is_null();
    free(head);
    head = NULL;

    return 0;
}

static void test_display_values(void)
{
    Node *nextNode = malloc(sizeof(Node));
    nextNode->value = 20;
    nextNode->next = NULL;
    head = malloc(sizeof(Node));
    head->value = 10;
    head->next = nextNode;

    int *values = display(head);

    assert(2 == length(head));
    assert(10 == values[0]);
    assert(20 == values[1]);
}

static void test_display_when_is_empty(void)
{
    display(head);

    assert(0 == length(head));
}

static void test_element_at_return_value_by_index(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);

    int *value = NULL;
    bool found = elementAt(head, 1, &value);

    assert(true == found);
    assert(10 == *value);
}
static void test_element_at_when_index_not_found(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);

    int *value = NULL;
    bool found = elementAt(head, -1, &value);

    assert(false == found);
}
static void test_element_at_when_list_is_null(void)
{
    int *value = NULL;
    bool found = elementAt(head, -1, &value);

    assert(false == found);
}

static void test_insert_one_value(void)
{
    insertInFront(&head, 10);

    int *values = display(head);
    assert(1 == length(head));
    assert(10 == values[0]);
}

static void test_insert_value_in_front(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);

    int *values = display(head);
    assert(2 == length(head));
    assert(20 == values[0]);
    assert(10 == values[1]);
}

static void test_delete_the_first_node(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);

    bool success = deleteInFront(&head);

    assert(true == success);
    int *values = display(head);
    assert(1 == length(head));
    assert(10 == values[0]);
}

static void test_delete_when_list_is_null(void)
{
    bool success = deleteInFront(&head);

    assert(false == success);
}

static void test_delete_last_node_by_index(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);
    insertInFront(&head, 30);

    bool success = deleteByIndex(&head, 2);

    assert(true == success);
    assert(2 == length(head));
    int *values = display(head);
    assert(30 == values[0]);
    assert(20 == values[1]);
}

static void test_delete_first_node_by_index(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);
    insertInFront(&head, 30);

    bool success = deleteByIndex(&head, 0);

    assert(true == success);
    assert(2 == length(head));
    int *values = display(head);
    assert(20 == values[0]);
    assert(10 == values[1]);
}

static void test_delete_when_index_not_found(void)
{
    insertInFront(&head, 10);
    insertInFront(&head, 20);
    insertInFront(&head, 30);

    bool success = deleteByIndex(&head, -1);

    assert(false == success);
    assert(3 == length(head));
    int *values = display(head);
    assert(30 == values[0]);
    assert(20 == values[1]);
    assert(10 == values[2]);
}

static void test_delete_by_index_when_list_is_null(void)
{
    bool success = deleteByIndex(&head, 1);

    assert(false == success);
    assert(0 == length(head));
}