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
    _execl(
        "C:\\Windows\\System32\\PING.EXE",
        "C:\\Windows\\System32\\PING.EXE",
        "google.com",
        NULL
    );
    printf("Ping Finished executing\n");
    return 0;
}