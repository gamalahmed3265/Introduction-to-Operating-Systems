/********** dlist Program C2.5.c **********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    int key;
} NODE;
NODE *dlist;                         // dlist is a NODE pointer
int insert2end(NODE **list, int key) // insert to list END
{
    NODE *p, *q;
    // printf("insert2end: key=%d ", key);
    p = (NODE *)malloc(sizeof(NODE));
    p->key = key;
    p->next = 0;
    q = *list;
    if (q == 0)
    { // list empty
        *list = p;
        p->next = p->prev = 0;
    }
    else
    {
        while (q->next) // step to LAST element
            q = q->next;
        q->next = p; // add p as last element
        p->prev = q;
    }
}
int insert2front(NODE **list, int key) // insert to list FRONT
{
    NODE *p, *q;
    // printf("insert2front: key=%d ", key);
    p = (NODE *)malloc(sizeof(NODE));
    p->key = key;
    p->prev = 0; // no previous node
    q = *list;
    if (q == 0)
    { // list empty
        *list = p;
        p->next = 0;
    }
    else
    {
        p->next = *list;
        q->prev = p;
        *list = p;
    }
}
void printForward(NODE *list) // print list forward
{
    printf("list forward =");
    while (list)
    {
        printf("[%d]->", list->key);
        list = list->next;
    }
    printf("NULL\n");
}
void printBackward(NODE *list) // print list backward
{
    printf("list backward=");
    NODE *p = list;
    if (p)
    {
        while (p->next) // step to last element
            p = p->next;
        while (p)
        {
            printf("[%d]->", p->key);
            p = p->prev;
        }
    }
    printf("NULL\n");
}
NODE *search(NODE *list, int key) // search for an element with a key
{
    NODE *p = list;
    while (p)
    {
        if (p->key == key)
        {
            printf("found %d at %x\n", key, (unsigned int)p);
            return p;
        }
        p = p->next;
    }
    return 0;
}
int delete(NODE **list, NODE *p) // delete an element pointed by p
{
    NODE *q = *list;
    if (p->next == 0 && p->prev == 0)
    { // p is the only node
        *list = 0;
    }
    else if (p->next == 0 && p->prev != 0)
    { // last but NOT first
        p->prev->next = 0;
    }
    else if (p->prev == 0 && p->next != 0)
    { // first but NOT last
        *list = p->next;
        p->next->prev = 0;
    }
    else
    { // p is an interior node
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    free(p);
}
int main()
{
    int i, key;
    NODE *p;
    printf("dlist program #1\n");
    printf("insert to END\n");
    dlist = 0; // initialize dlist to empty
    for (i = 0; i < 8; i++)
    {
        insert2end(&dlist, i);
    }
    printForward(dlist);
    printBackward(dlist);
    printf("insert to FRONT\n");
    dlist = 0; // initialize dlist to empty
    for (i = 0; i < 8; i++)
    {
        insert2front(&dlist, i);
    }
    printForward(dlist);
    printBackward(dlist);
    printf("test delete\n");
    while (1)
    {
        printf("enter a key to delete: ");
        scanf("%d", &key);
        if (key < 0)
            exit(0); // exit if negative key
        p = search(dlist, key);
        if (p == 0)
        {
            printf("key %d not found\n", key);
            continue;
        }
        delete (&dlist, p);
        printForward(dlist);
        printBackward(dlist);
    }
}