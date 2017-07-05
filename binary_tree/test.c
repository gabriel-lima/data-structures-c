#include "../xunit/runner.h"
#include <assert.h>
#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

/*begin: tests to function insertNode */
static void test_insert_one_node();
static void test_insert_two_nodes();
static void test_insert_three_nodes();
static void test_insert_four_nodes();
static void test_doesnt_insert_when_node_is_null();
static void test_doesnt_insert_when_tree_is_null();
/*end: tests to function insertNode */

/* begin tests to function searchNode */
static void test_search_node_with_one_depth();
static void test_search_node_with_two_depth();
static void test_search_node_with_three_depth();
static void test_null_when_doesnt_search_node();
static void test_null_when_tree_is_null();
/* end tests to function searchNode */

static void setUp();
static void tearDown();

int main()
{
    Runner *runner = init(&setUp, &tearDown);
    
    /*begin: tests to function insertNode */
    registerTest(runner, &test_insert_one_node);
    registerTest(runner, &test_insert_two_nodes);
    registerTest(runner, &test_insert_three_nodes);
    registerTest(runner, &test_insert_four_nodes);
    registerTest(runner, &test_doesnt_insert_when_node_is_null);
    registerTest(runner, &test_doesnt_insert_when_tree_is_null);
    /*end: tests to function insertNode */

    /* begin tests to function searchNode */
    registerTest(runner, &test_search_node_with_one_depth);
    registerTest(runner, &test_search_node_with_two_depth);
    registerTest(runner, &test_search_node_with_three_depth);
    registerTest(runner, &test_null_when_doesnt_search_node);
    registerTest(runner, &test_null_when_tree_is_null);
    /* end tests to function searchNode */

    run(runner);
}

BinaryTree *tree;

static void setUp()
{
    tree = newBinaryTree();
}
static void tearDown()
{
    destroyBinaryTree(tree);
}

/*begin: tests to function insertNode */
static void test_insert_one_node()
{
    insertNode(tree, newNode(10));
    
    assert(10 == tree->root->value);
    
    assert(NULL == tree->root->left);
    assert(NULL == tree->root->right);
}

static void test_insert_two_nodes()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    
    assert(10 == tree->root->value);

    assert(8 == tree->root->left->value);
    assert(NULL == tree->root->left->left);
    assert(NULL == tree->root->left->right);
    
    assert(NULL == tree->root->right);
}

static void test_insert_three_nodes()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    
    assert(10 == tree->root->value);

    assert(8 == tree->root->left->value);
    assert(NULL == tree->root->left->left);
    assert(NULL == tree->root->left->right);

    assert(12 == tree->root->right->value);
    assert(NULL == tree->root->right->left);
    assert(NULL == tree->root->right->right); 
}

static void test_insert_four_nodes()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    insertNode(tree, newNode(9));
    
    assert(10 == tree->root->value);

    assert(8 == tree->root->left->value);
    assert(NULL == tree->root->left->left);
    assert(9 == tree->root->left->right->value);
    assert(NULL == tree->root->left->right->left);
    assert(NULL == tree->root->left->right->right);

    assert(12 == tree->root->right->value);
    assert(NULL == tree->root->right->left);
    assert(NULL == tree->root->right->right); 
}

static void test_doesnt_insert_when_node_is_null()
{
    insertNode(tree, NULL);

    assert(NULL == tree->root);
}

static void test_doesnt_insert_when_tree_is_null()
{
    insertNode(NULL, newNode(10));

    assert(NULL == tree->root);
}
/* end: tests to function insertNode */

/* begin tests to function searchNode */
static void test_search_node_with_one_depth()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    insertNode(tree, newNode(9));

    Node *node = searchNode(tree, 10);

    assert(10 == node->value);
}

static void test_search_node_with_two_depth()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    insertNode(tree, newNode(9));

    Node *node = searchNode(tree, 8);

    assert(8 == node->value);
}

static void test_search_node_with_three_depth()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    insertNode(tree, newNode(9));

    Node *node = searchNode(tree, 9);

    assert(9 == node->value);
}

static void test_null_when_doesnt_search_node()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    insertNode(tree, newNode(9));

    Node *node = searchNode(tree, 0);

    assert(NULL == node);
}

static void test_null_when_tree_is_null()
{
    insertNode(tree, newNode(10));
    insertNode(tree, newNode(8));
    insertNode(tree, newNode(12));
    insertNode(tree, newNode(9));

    Node *node = searchNode(NULL, 10);

    assert(NULL == node);
}
/* end tests to function searchNode */
