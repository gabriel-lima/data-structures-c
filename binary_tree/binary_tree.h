typedef struct Node
{
    int value;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct BinaryTree
{
    struct Node *root;
    int length;
} BinaryTree;

BinaryTree *newBinaryTree();
void destroyBinaryTree(BinaryTree *binaryTree);
Node *newNode(int value);
void insertNode(BinaryTree *tree, Node *nodeToInsert);
void recursiveInsertNode(Node *current, Node *nodeToInsert);
Node *searchNode(BinaryTree *tree, int value);
