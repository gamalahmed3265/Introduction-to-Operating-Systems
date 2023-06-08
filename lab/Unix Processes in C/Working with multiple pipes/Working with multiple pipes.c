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
    int fd[3][2];
    // fd[0] - read
    // fd[1] - write

    for (int i = 0; i < 3; i++)
    {
        if (pipe(fd[i]) == -1)
        {
            printf("An error ocurred with opening the pip\n");
            return 1;
        }
    }

    int pid = fork();
    if (pid == -1)
    {
        return 1;
    }

    if (pid == 0)
    {
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);
        close(fd[2][1]);
        int x;
        if (read(fd[0][0], &x, sizeof(int)))
        {
            return 3;
        }

        x += 5;
        if (write(fd[1][1], &x, sizeof(int)))
        {
            return 4;
        }
        close(fd[0][0]);
        close(fd[1][1]);
    }

    // pid 2

    int pid2 = fork();
    if (pid2 == -1)
    {
        return 1;
    }

    if (pid2 == 0)
    {
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);
        int x;
        if (read(fd[1][0], &x, sizeof(int)))
        {
            return 6;
        }

        x += 5;
        if (write(fd[2][1], &x, sizeof(int)))
        {
            return 7;
        }
        close(fd[1][0]);
        close(fd[2][1]);
    }

    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);

    int x;
    printf("Input Number: ");
    scanf("%d", &x);

    if (write(fd[0][1], &x, sizeof(int)))
    {
        return 8;
    }
    if (read(fd[2][0], &x, sizeof(int)))
    {
        return 9;
    }
    printf("results %d\n", x);
    close(fd[0][1]);
    close(fd[2][0]);

    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
