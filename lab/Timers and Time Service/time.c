/************ time.c file ***********/
#include <stdio.h>
#include <time.h>
time_t start, end;
int main()
{
    int i;
    start = time(NULL);
    printf("start=%ld\n", start);
    for (i = 0; i < 123456789; i++)
        ; // delay to simulate computation
    end = time(NULL);
    printf("end =%ld time=%ld\n", end, end - start);
}