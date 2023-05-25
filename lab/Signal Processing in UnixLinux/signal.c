#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler(){
    write(STDOUT_FILENO,"I won'n die!\n",13);
}
int main()
{
    signal(SIGINT,handler);
    while (1)
    {
        printf("process id %d\n",getpid());
        sleep(1);
    }
    return 0;
}
