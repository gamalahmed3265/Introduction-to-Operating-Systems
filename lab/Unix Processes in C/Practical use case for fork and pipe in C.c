#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int arr[]={2,5,4,2,1,7,6};
    int sizeArr=sizeof(arr)/sizeof(int);
    printf("size of arr is: %d\n",sizeArr);
    int start,end;
    int fd[2];
    
    int id=fork();
    if (id==-1){
        printf("An error occured with forking the process\n");
            return 4;
    }
    // child send verible to parent and compute value
    if (id==0){
        
        start=0;
        end=start+sizeArr/2;
    }
    else{
        start=sizeArr/2;
        end=sizeArr;
    }

    printf("start: %d, end: %d\n",start,end);
    int sum=0;
    int i;
    for (i = start; i < end; i++){
        sum+=arr[i];
    }
    // will output start-end 0-3 = sum=11
    // will output start-end 3-7 = sum=16
    printf("Calc Practical  Sum is: %d\n",sum);

    // fd[0] - read
    // fd[1] - write

    if (pipe(fd)==-1){
        printf("An error ocurred with opening the pip\n");
        return 1;
    }
    if(id==0){
        // close the pipe read 
        close(fd[0]);
        
        // write d this value in fd
        if(write(fd[1],&sum,sizeof(sum))==-1){
            printf("An error occured with writing the pipe\n");
            return 2;
        }
        // close the pipe write 
        close(fd[1]);
    }
    else{
        int sumFromChild;
        // close the pipe write 
        close(fd[1]);
        if(read(fd[0],&sumFromChild,sizeof(sumFromChild))==-1){
            printf("An error occured with reading the pipe\n");
            return 2;
        }
        // close the pipe write 
        close(fd[0]);
        int totalSum=sum+sumFromChild;
        printf("Sum in All Proces %d\n",totalSum);
        wait(NULL);
    }
    return 0;
}
