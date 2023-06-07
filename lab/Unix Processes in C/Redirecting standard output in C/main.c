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
    int id=fork();
    if(id==-1){
        return 2;
    }
    if(id==0){
        int file=open("pingTest.txt",O_WRONLY| O_CREAT);
        if(file==-1){
            return 2;
        }
        printf("the fd pingResults: %d\n",file);
        int file2=dup2(file,STDOT_FILENO);
        printf("the duplicated df: %d\n",file2);
        close(file);
        //child
        int err=execlp("ping","ping","-c","3","google.com",NULL);
        if(id==-1){
                printf("Could not find Programe to excute!\n");
        return 2;
        }
    }
    else{
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)){
            int status=WEXITSTATUS(wstatus);
            if (status==0)
            {
            printf("Sucessful!\n");
            }
    else{
            printf("Failure!\n");

    }            
        }
        //parent process
        printf("Some post processing goes here\n");
    }
    return 0;
}