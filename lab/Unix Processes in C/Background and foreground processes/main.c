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

int main(int argc, char *argv[]){

    int x;
    printf("Enter number1\n");
    scanf("%d",&x);
    print("Reults %d *5 = %d\n",x,x*5);

    return 0;
}