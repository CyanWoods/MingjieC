//POSIX标准下可以用来计时的代码块

#include <time.h>
#include <stdio.h>
int main ()
{
    struct timespec start, end; 
    double time_elapsed;

    clock_gettime(CLOCK_REALTIME, &start);
    /*——————————————代码块——————————————*/
    /*——————————————代码块——————————————*/
    /*——————————————代码块——————————————*/
    /*——————————————代码块——————————————*/
    /*——————————————代码块——————————————*/
    clock_gettime(CLOCK_REALTIME, &end);

    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    time_elapsed = seconds + nanoseconds*1e-9;

    printf("用时%.1f秒。\n", time_elapsed);
    return 0;
}