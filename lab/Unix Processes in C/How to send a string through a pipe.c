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
        // close the pipe read
        close(fd[0]);

        char str[200];
        int n;
        printf("Input String: ");
        fgets(str, 200, stdin);
        n = strlen(str) + 1;

        str[n - 1] = '\0';

        if (write(fd[1], &n, sizeof(int)) == -1)
        {
            printf("An error occured with writing the pipe\n");
            return 3;
        }
        if (write(fd[1], str, sizeof(char) * n) == -1)
        {
            printf("An error occured with writing the pipe\n");
            return 2;
        }
        // close the pipe write
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char str[200];
        int n;
        if (read(fd[0], &n, sizeof(int)) == -1)
        {
            printf("An error occured with writing the pipe\n");
            return 4;
        }
        if (read(fd[0], &str, sizeof(char) * n) == -1)
        {
            printf("An error occured with writing the pipe\n");
            return 5;
        }
        // for (i = 0; i < strlen(str); i++)
        // {
        //     printf("%d",str[0]);
        // }
        // printf("\n");
        printf("Receiving String is %s\n", str);
        close(fd[0]);
        wait(NULL);
    }

    return 0;
}
