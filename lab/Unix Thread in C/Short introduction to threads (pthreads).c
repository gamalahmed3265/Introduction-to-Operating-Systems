#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>


void* routine(){
    printf("Test from Thread inside process id: %d\n",getpid());
    sleep(3);
    printf("Ending Thread\n");
}
int main(int argc,char*argv[]){
    pthread_t t1;
    pthread_t t2;
    if (pthread_create(&t1,NULL,&routine,NULL)==0)
        return 1;
    if( pthread_create(&t2,NULL,&routine,NULL)==0)
        return 2;
    if (pthread_join(t1,NULL) !=0)
        return 3;
    if (pthread_join(t2,NULL) !=0)
        return 4;
    return 0;
}
