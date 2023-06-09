/********* t.c file *********/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#define NPROC 9
#define SSIZE 1024
// PROC status
#define FREE 0
#define READY 1
#define SLEEP 2
#define BLOCK 3
#define PAUSE 4
#define ZOMBIE 5
typedef struct proc
{
    struct proc *next;
    int ksp;      // saved sp when NOT running
    int pid;      // task PID
    int priority; // task priority
    int status;   // status=FREE|READY, etc.
    int event;    // sleep event
    int exitStatus;
    int joinPid;
    struct proc joinPtr;
    int time;         // time slice in ticks
    int pause;        // pause time in seconds
    int stack[SSIZE]; // per task stack
} PROC;
PROC proc[NPROC]; // task PROCs
PROC *freeList, *readyQueue, *running;
PROC *sleepList;   // list of SLEEP tasks
PROC *pauseList;   // list of PAUSE tasks
#include “queue.c” // same queue.c file as before
#include “wait.c”  // tsleep, twakeup, texit, join functions
int menu()         // command menu: to be expanded later
{
    printf("*********** menu ***********\n");
    printf("* create switch exit ps *\n");
    printf("****************************\n");
}
int init()
{
    int i, j;
    PROC *p;
    for (i = 0; i < NPROC; i++)
    {
        p = &proc[i];
        p->pid = i;
        p->priority = 1;
        p->status = FREE;
        p->event = 0;
        p->next = p + 1;
    }
    proc[NPROC - 1].next = 0;
    freeList = &proc[0]; // all PROCs in freeList
    readyQueue = 0;
    sleepList = 0;
    pauseList = 0;
    // create P0 as initial running task
    running = dequeue(&freeList);
    running->status = READY;
    running->priority = 0; // P0 has lowest priority 0
    printList("freeList", freeList);
    printf("init complete: P0 running\n");
}
int do_exit() // task exit as FREE
{
    printf("task %d exit: ", running->pid);
    running->status = FREE;
    running->priority = 0;
    enqueue(&freeList, running);
    printList("freeList", freeList);
    tswitch();
}
int do_ps() // print task status
{
    printf("--------- ps ----------\n");
    printList("readyQueue", readyQueue);
    printList("sleepList ", sleepList);
    printf("---------------------–\n");
}
int create(void(f)(), void *parm) // create a new task
{
    int i;
    PROC *p = dequeue(&freeList);
    if (!p)
    {
        printf("create failed\n");
        return -1;
    }
    p->ppid = running->pid;
    p->status = READY;
    p->priority = 1;
    for (i = 1; i < 12; i++)
        p->stack[SSIZE - i] = 0;
    p->stack[SSIZE - 1] = (int)parm;
    p->stack[SSIZE - 2] = (int)do_exit;

    p->stack[SSIZE - 3] = (int)f;
    p->ksp = &p->stack[SSIZE - 12];
    enqueue(&readyQueue, p);
    printf("%d created a new task %d\n", running->pid, p->pid);
    return p->pid;
}
void func(void *parm) // task function
{
    char line[64], cmd[16];
    printf("task %d start: parm = %d\n", running->pid, parm);
    while (1)
    {
        printf("task %d running\n", running->pid);
        menu();
        printf("enter a command line: ");
        fgets(line, 64, stdin);
        line[strlen(line) - 1] = 0; // kill \n at end of line
        sscanf(line, "%s", cmd);
        if (strcmp(cmd, "create") == 0)
            create((void *)func, 0);
        else if (strcmp(cmd, "switch") == 0)
            tswitch();
        else if (strcmp(cmd, "exit") == 0)
            do_exit();
        else if (strcmp(cmd, "ps") == 0)
            do_ps();
    }
}
int main()
{
    int i;
    printf("Welcome to the MT multitasking system\n");
    init();
    for (i = 1; i < 5; i++) // create tasks
        create(func, 0);
    printf("P0 switch to P1\n");
    while (1)
    {
        if (readyQueue)
            tswitch();
    }
}
int scheduler()
{
    if (running->status == READY)
        enqueue(&readyQueue, running);
    running = dequeue(&readyQueue);
    printf("next running = %d\n", running->pid);
}