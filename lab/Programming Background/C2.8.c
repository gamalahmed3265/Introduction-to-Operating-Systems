/***** C2.8.c file: print binary tree by levels *****/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    int key;
    struct node *right;
} NODE;
typedef struct qe
{                      // queue element structure
    struct qe *next;   // queue pointer
    struct node *node; // queue contents
} QE;                  // queue element type
int enqueue(QE **queue, NODE *node)
{
    QE *q = *queue;
    QE *r = (QE *)malloc(sizeof(QE));
    r->node = node;
    if (q == 0)
        *queue = r;
    else
    {
        while (q->next)
            q = q->next;
        q->next = r;
    }
    r->next = 0;
}
NODE *dequeue(QE **queue)
{
    QE *q = *queue;
    if (q)
        *queue = q->next;
    return q->node;
}
int qlength(QE *queue)
{
    int n = 0;
    while (queue)
    {
        n++;
        queue = queue->next;
    }
    return n;
}
// print a binary tree by levels, each level on a line
void printLevel(NODE *root)
{
    int nodeCount;
    if (root == NULL)
        return;
    QE queue = 0;          // create a FIFO queue
    enqueue(&queue, root); // start with root
    while (1)
    {
        nodeCount = qlength(queue);
        if (nodeCount == 0)
            break;
        // dequeue nodes of current level, enqueue nodes of next level
        while (nodeCount > 0)
        {
            NODE *node = dequeue(&queue);
            printf("%d ", node->key);
            if (node->left != NULL)
                enqueue(&queue, node->left);
            if (node->right != NULL)
                enqueue(&queue, node->right);
            nodeCount--;
        }
        printf("\n");
    }
}
NODE *newNode(int key) // create a new node
{
    NODE *t = (NODE *)malloc(sizeof(NODE));
    t->key = key;
    t->left = NULL;
    t->right = NULL;
    return t;
}
int main() // driver program to test printLevel()
{
    queue = 0;
    // create a simple binary tree
    NODE *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->leftt = newNode(6);
    root->right->right = 0; // right child = 0
    printLevel(root);
    return 0;
}