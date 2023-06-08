#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char*argv[]){
    int id=fork();
    if (id==0){// child p wait
        sleep(1);
    }
    printf("Current id=> %d , parent id=> %d\n",getpid(),getppid());

    int res=wait(NULL);
    if (res==-1){
        printf("No Children to wait for \n");
    }
    else{
        printf("%d finished execution\n",res);
    }
    return 0;
}