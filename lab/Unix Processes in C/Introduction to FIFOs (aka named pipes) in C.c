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
    if (mkfifo("mkfifo",0777)==-1){
        if (errno !=EEXIST){
            printf("Could not create file fifo\n");
            return 1;
        }
    }
    printf("Opening...\n");
    int fd=open("mkfifo",O_WRONLY);
    int x=97;
    if(write(fd,&x,sizeof(x))==-1){
        return 2;
    }
    printf("Writing...\n");
    close(fd);
    printf("closeing...\n");
    return 0;
}