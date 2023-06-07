#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int arr[5];
    int srand(time(NULL));

    int i;
    for (i = 0; i < 5; i++)
    {
        arr[i] = rand() % 100;
    }

    int fd = open("mkfifo", O_WRONLY);
    if (fd == -1)
    {
        return -1;
    }
    for (i = 0; i < 5; i++)
    {
        if (write(fd, &arr[i], sizeof(int)) == -1)
        {
            return 2;
        }
        printf("wrote %d\n",arr[i]);
    }

    close(fd);

    return 0;
}