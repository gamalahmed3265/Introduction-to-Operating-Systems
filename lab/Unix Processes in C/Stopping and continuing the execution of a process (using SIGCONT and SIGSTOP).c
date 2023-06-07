#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int pid=fork();
    if(pid==-1){
        return 2;
    }
    if(pid==0){
        while(1){
            printf("some text goes here\n");
            usleep(50000);
        }
    }
    else{
        kill(pid,SIGSTOP);
        sleep(1);//one secode
        kill(pid,SIGCONT);
        sleep(1);//one secode
        kill(pid,SIGKILL);
        wait(NULL);
    }
    return 0;
}