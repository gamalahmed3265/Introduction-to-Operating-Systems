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
#include <time.h>
int x=0;
void handler(int sig){
    if (x==0){
        printf("hint remember multiplication is repetitive addition\n");
    }
}
int main(int argc, char *argv[]){
     int fd[2];
    // fd[0] - read
    // fd[1] - write

    if (pipe(fd)==-1){
        printf("An error ocurred with opening the pip\n");
        return 1;
    }

    int pid=fork();
    if(pid==-1){
        return -1;
    }

    if(pid==0){
         // close the pipe read 
        close(fd[0]);
        int n,i;
        int arr[10];
         srand(time(NULL));
        n=rand()%10+1;
        for (i = 0; i < 10; i++){
            arr[i]=rand() %11;
        }
        if(write(fd[1],&n,sizeof(int))==-1){
            printf("An error occured with writing the pipe\n");
            return 2;
        }
        if(write(fd[1],&arr,sizeof(int) *n)==-1){
            printf("An error occured with writing the pipe\n");
            return 2;
        }
        // close the pipe write 
        close(fd[1]);
        
    }
    else{
        close(fd[1]);
         int n,i;
        int arr[10];
         if(read(fd[0],&n,sizeof(int))==-1){
            printf("An error occured with reading the pipe\n");
            return 2;
        }
        if(read(fd[0],&arr,sizeof(int)*n)==-1){
            printf("An error occured with reading the pipe\n");
            return 2;
        }
       
        
        // close the pipe write 
        close(fd[0]);
        for (i = 0; i < n; i++){
            sum+=arr[i];
        }
        printf("sum is %d\n",sum);
        wait(NULL);
    }
    
    
    

    return 0;
}