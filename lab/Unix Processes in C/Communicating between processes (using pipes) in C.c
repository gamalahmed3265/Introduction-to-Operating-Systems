#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int fd[2];
    // fd[0] - read
    // fd[1] - write

    if (pipe(fd)==-1){
        printf("An error ocurred with opening the pip\n");
        return 1;
    }
    int id=fork();
    if (id==-1){
        printf("An error occured with forking the process\n");
            return 4;
    }
    // child send verible to parent and compute value
    if (id==0){
        // close the pipe read 
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d",&x);
        // write d this value in fd
        if(write(fd[1],&x,sizeof(int))==-1){
            printf("An error occured with writing the pipe\n");
            return 2;
        }
        // close the pipe write 
        close(fd[1]);
    }
    else{
        // close the pipe write 
        close(fd[1]);
        int y;
        if(read(fd[0],&y,sizeof(int))==-1){
            printf("An error occured with reading the pipe\n");
            return 2;
        }
        //example we will y*3
        y=y*3;
        // close the pipe write 
        close(fd[0]);
        printf("Get from child proces %d\n",y);
    }
    return 0;
}
