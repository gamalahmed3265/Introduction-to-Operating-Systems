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
    int arr[5];
    int fd=open("sum",O_RDONLY);
    if (FD==-1){
        return 1;
    }
    int i;
    for (i = 0; i < 5; i++){
        if(read(fd,&arr[i],sizeof(int)) ==-1){
            return 2;
        }
        printf("Recive %d\n",arr[i]);
    }
    close(fd);
    
    return 0;
}