#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int arr[]={2,5,4,2,1,7,6,};
    int sizeArr=sizeof(arr)/sizeof(int);
    int start,end;
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
        
        start=0;
        end=start+sizeArr/2;
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
        start=sizeArr/2;
        end=sizeArr;

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


    int sum=0;
    int i;
    for (i = start; i < end; i++){
        sum+=arr[i];
    }
    printf("Calc Practical  Sum is: %d\n",sum);

    return 0;
}