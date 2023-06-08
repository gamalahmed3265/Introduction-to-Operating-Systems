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
#include <string.h>

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        printf("Error Message\n");
        return 1;
    }

    if (pid == 0)
    {
        sleep(4);
        printf("Finished execution (%d)\n", getpid());
        return 0;
    }

    int pid2 = fork();
    if (pid2 == -1)
    {
        printf("Error Message\n");
        return 2;
    }

    if (pid2 == 0)
    {
        sleep(1);
        printf("Finished execution (%d)\n", getpid());
        return 0;
    }

    int pid1_res = wait(NULL);
    printf("Waited for %d\n", pid1_res);
    int pid2_res = wait(NULL);
    printf("Waited for %d\n", pid_res);
    return 0;
}