#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char*argv[]){
    int pid=fork();
    if (pid==-1)
        return -1;
    print("Hello Process\n");

    if(pid!=0)
        wait(NULL);
    return 0;
}
