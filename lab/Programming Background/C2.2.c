/**************** C2.2.c file *****************/
#include "type.h"
NODE *mylist, *node; // pointers, no NODE area yet
int printlist(NODE *p)
{ // same as in C2.1
}
int main()
{
    int i;
    NODE *p;
    node = (NODE *)malloc(N * sizeof(NODE)); // node->N*72 bytes in HEAP
    for (i = 0; i < N; i++)
    {
        p = &node[i]; // access each NODE area in HEAP
        sprintf(p->name, "%s%d", "node", i);
        p->id = i;
        p->next = p + 1; // node[i].next = &node[i+1];
    }
    node[N - 1].next = 0;
    mylist = &node[0];
    printlist(mylist);
}