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
int x=0;
void handler(int sig){
    if (x==0){
        printf("hint remember multiplication is repetitive addition\n");
    }
}
int main(int argc, char *argv[]){
    int pid=fork();
    if(pid==-1){
        return -1;
    }

    if(pid==0){
        sleep(5);
        kill(getppid(),STGUSR1);
    }
    else{
        struct sigaction act={0};
        act.sa_handler = &handler;
        act.sa_flags = SA_RESTART;
        sigaction(STGUSR1, &act, NULL);

        int x;
        printf("what reults of 3*5: \n");
        scanf("%d",&x);
        if(x==15){
            printf("Right\n");
        }
            else{
            printf("Wrong\n");
            }
            
            wait(NULL);
    }
    
    
    

    return 0;
}