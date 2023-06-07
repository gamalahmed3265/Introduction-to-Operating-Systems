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

void handler(int sig){
    printf("stop not allowed\n");
}
int main(int argc, char *argv[]){
    struct sigaction act;
    act.sa_handler = &handler;
    act.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &act, NULL);
    printf("proc PID=%d looping\n",getpid());
    
    // signal(SIGTSTP,&handler);

    int x;
    printf("Enter number1\n");
    scanf("%d",&x);
    print("Reults %d *5 = %d\n",x,x*5);

    return 0;
}