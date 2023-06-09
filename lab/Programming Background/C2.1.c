/*********************** C2.1.c file **********************/
#include "type.h"
NODE *mylist, node[N]; // in bss section of program run-time image
int printlist(NODE *p) // print list function
{
    while (p)
    {
        printf("[%s %d]->", p->name, p->id);
        p = p->next;

        printf("NULL\n");
    }
}
int main()
{
    int i;
    NODE *p;
    for (i = 0; i < N; i++)
    {
        p = &node[i];
        sprintf(p->name, "%s%d", "node", i); // node0, node1, etc.
        p->id = i;                           // used node index as ID
        p->next = p + 1;                     // node[i].next = &node[i+1];
    }
    node[N - 1].next = 0;
    mylist = &node[0]; // mylist points to node[0]
    printlist(mylist); // print mylist elements
}