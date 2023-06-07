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
    printf("Calc Practical  Sum is: %d\n",sum);

    return 0;
}
