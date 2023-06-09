/**************** C2.3.c file *****************/
#include "type.h"
NODE *mylist, *node; // pointers, no NODE area yet
int printlist(NODE *p)
{ // same as in L1.c
}
int main()
{
    int i;
    NODE *p, *q;
    for (i = 0; i < N; i++)
    {
        p = (NODE *)malloc(sizeof(NODE)); // allocate a node in heap
        sprintf(p->name, "%s%d", "node", i);
        p->id = i;
        p->next = 0; // node[i].next = 0;
        if (i == 0)
        {
            mylist = q = p; // mylist -> node0; q->current node
        }
        q->next = p;
        q = p;
    }
    printlist(mylist);
}