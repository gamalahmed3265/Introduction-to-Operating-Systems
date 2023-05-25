/****** sigaction.c file *******/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler(int sig, siginfo_t *siginfo, void *context)
{
    printf("handler: sig=%d from PID=%d UID=%d\n",sig, siginfo->si_pid, siginfo->si_uid);
}
int main(int argc, char *argv[])
{
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM, &act, NULL);
    printf("proc PID=%d looping\n”);
    printf(“enter kill PID to send SIGTERM signal to it\n", getpid());
    while(1){
            sleep(10);
        }
}
