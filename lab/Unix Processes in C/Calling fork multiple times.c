#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int id1 = fork();
    int id2 = fork();
    if (id1 == 0){ // child p wait
        if (id2 == 0){
            printf("We are process y Current id=> %d , parent id=> %d\n",getpid(),getppid());
        }
        else{
            printf("We are process x Current id=> %d , parent id=> %d\n",getpid(),getppid());
        }
    }
    else{
        if (id2 == 0){
            printf("We are process z Current id=> %d , parent id=> %d\n",getpid(),getppid());
        }
        else{
            printf("We are the parent Current id=> %d , parent id=> %d\n",getpid(),getppid());
        }
    }

    return 0;
}
