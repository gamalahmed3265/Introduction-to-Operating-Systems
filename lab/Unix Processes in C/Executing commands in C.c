#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]){
    int id=fork();
    if(id==-1){
        return 2;
    }
    if(id==0){
        //child
        execlp("ping","ping","-c","3","google.com",NULL);
        printf("Sucessful!");
    }
    else{
        //parent process
        printf("Sucessful!\n");
        printf("Some post processing goes here\n");
    }
    return 0;
}
