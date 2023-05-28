
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int maills=0;
pthread_mutex_t mutex;
void* routine(){
    for (int i = 0; i < 1000000; i++)
    {
        // Lock the mutex
        pthread_mutex_lock(&mutex);
        maills++;
        // Unlock the mutex
    pthread_mutex_unlock(&mutex);
    }
    
}
int main(int argc,char*argv[]){
    pthread_t t1,t2;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    if (pthread_create(&t1,NULL,&routine,NULL)==0)
        return 1;
    if( pthread_create(&t2,NULL,&routine,NULL)==0)
        return 2;
    if (pthread_join(t1,NULL) !=0)
        return 3;
    if (pthread_join(t2,NULL) !=0)
        return 4;
    printf("Number of mails %d/n",maills);

     // Destroy the mutex
    pthread_mutex_destroy(&mutex);
    return 0;
}