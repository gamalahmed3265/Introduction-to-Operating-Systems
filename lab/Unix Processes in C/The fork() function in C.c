#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char*argv[]){
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("I am the child process\n");
    } else {
        printf("I am the parent process, my child's PID is %d\n", pid);
    }

    return 0;
}