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

    if (pip(fd)==-1){
        printf("An error ocurred with opening the pip\n");
    }
    int id=fork();
    // child send verible to parent and compute value
    if (id==0){
        // close the pipe read 
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d",&x);
        // write d this value in fd
        write(fd[1],&x,sizeof(int));
        // close the pipe write 
        close(fd[1]);
    }
    else{
        // close the pipe write 
        close(fd[1]);
        int y;
        read(fd[0],&y,sizeof(int));
        // close the pipe write 
        close(fd[0]);
        printf("Get from child proces %d\n",y);
    }
    return 0;
}