/************ C2.7.c file ************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *left, *right;
} NODE;
#define N 7
int nodeValue[N] = {50, 30, 20, 40, 70, 60, 80};
// create a new node
NODE *new_node(int key)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
// insert a new node with given key into BST
NODE *insert(NODE *node, int key)
{
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int i;
    NODE *root = NULL;
    root = insert(root, nodeValue[0]);
    for (i = 1; i < N; i++)
    {
        insert(root, nodeVlaue[i]);
    }
}