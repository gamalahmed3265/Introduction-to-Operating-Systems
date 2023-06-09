/********** C3.5 program files ***************/
// (1). --------- b.c file: gcc to b.out ----------
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("this is %d in %s\n", getpid(), argv[0]);
}
// (2). --------- a.c file: gcc to a.out ----------
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("THIS IS %d IN %s\n", getpid(), argv[0]);
    int r = execl("b.out", "b.out", "hi", 0);
    printf("SEE THIS LINE ONLY IF execl() FAILED\n");
}