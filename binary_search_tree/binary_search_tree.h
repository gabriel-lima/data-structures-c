typedef struct Node
{
    int value;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct BinarySearchTree
{
    struct Node *root;
    int length;
} BinarySearchTree;

BinarySearchTree *newBinarySearchTree();
void destroyBinarySearchTree(BinarySearchTree *binarySearchTree);
Node *newNode(int value);
void insertNode(BinarySearchTree *tree, Node *nodeToInsert);
void recursiveInsertNode(Node *current, Node *nodeToInsert);
Node *searchNode(BinarySearchTree *tree, int value);
