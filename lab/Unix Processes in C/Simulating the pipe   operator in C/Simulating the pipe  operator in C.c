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
    int fd[2];
    // fd[0] - read
    // fd[1] - write

    if (pipe(fd) == -1)
    {
        printf("An error ocurred with opening the pip\n");
        return 1;
    }
    int pid = fork();
    if (pid == -1)
    {
        return 1;
    }

    if (pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp(
            "ping",
            "ping",
            "-c",
            "5",
            "google.com",
            NULL);
    }
    int pid2 = fork();
    if (pid2 == -1)
    {
        return 2;
    }
    if (pid2 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp(
            "grep",
            "grep",
            "rtt",
            NULL);
    }
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}