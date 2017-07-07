#include <stdlib.h>
#include "binary_search_tree.h"

BinarySearchTree *newBinarySearchTree()
{
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    tree->root = NULL;
    tree->length = 0;
    return tree;
}

void destroyBinarySearchTree(BinarySearchTree *binarySearchTree)
{
    free(binarySearchTree);
}

Node *newNode(int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void insertNode(BinarySearchTree *tree, Node *nodeToInsert)
{
    if (tree == NULL || nodeToInsert == NULL)
        return;

    if (tree->root == NULL)
        tree->root = nodeToInsert;
    else
        recursiveInsertNode(tree->root, nodeToInsert);

    tree->length++;
}

void recursiveInsertNode(Node *current, Node *nodeToInsert)
{
    if (nodeToInsert->value <= current->value)
    {
        if (current->left == NULL)
            current->left = nodeToInsert;
        else
            recursiveInsertNode(current->left, nodeToInsert);
    }
    else
    {
        if (current->right == NULL)
            current->right = nodeToInsert;
        else
            recursiveInsertNode(current->right, nodeToInsert);
    }
}

Node *searchNode(BinarySearchTree *tree, int value)
{
    if (tree == NULL)
        return NULL;

    Node *current = tree->root;
    while (current != NULL)
    {
        if (value == current->value)
            return current;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return NULL;
}
