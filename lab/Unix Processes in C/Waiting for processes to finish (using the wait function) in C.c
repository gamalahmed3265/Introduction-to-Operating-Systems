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
    int n;
    if (pid == 0) {
        n=1;
    } else {
        n=6;
    }
    if (pid != 0) {
        wait();
    }
    for (int i = n; i < n+1; i++){
        printf("%d ",i);
        fflush(stdout);
    }
    if (pid != 0) {
        print("\n");
    }
    return 0;
}
