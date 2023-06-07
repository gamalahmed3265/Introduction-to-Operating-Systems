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
    execlp("ping","ping","-c","3","google.com".NULL);
    printf("Sucessful!");
    return 0;
}