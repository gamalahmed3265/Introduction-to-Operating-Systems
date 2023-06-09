#include <stdlib.h>
#include <sys/time.h>
struct timeval t;
int main()
{
    gettimeofday(&t, NULL);
    printf("sec=%ld usec=%d\n", t.tv_sec, t.tv_usec);
    printf((char *)ctime(&t.tv_sec));
}