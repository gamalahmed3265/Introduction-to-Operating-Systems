/***************** C2.4.c file **************/
#include "type.h"
NODE *mylist;
int main()
{
    char line[128], name[64];
    int id;
    NODE *p;
    mylist = 0; // initialize mylist to empty list
    while (1)
    {
        printf("enter node name and id value : ");
        fgets(line, 128, stdin);    // get an input line
        line[strlen(line) - 1] = 0; // kill \n at end
        if (line[0] == 0)           // break out on empty input line
            break;
        sscanf("% s % d", name, &id); // extract name string and id value
        p = (NODE *)malloc(sizeof(NODE));
        if (p == 0)
            exit(-1); // out of HEAP memory
        strcpy(p->name, name);
        p->id = id;
        insert(&mylist, p); // insert p to list end
        printlist(mylist);
    }
}