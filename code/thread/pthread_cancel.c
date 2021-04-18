#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *thrd_func1(){
    printf("thread 1 returning\n");
    return((void*)100);
}

void *thrd_func2(){
    printf("thread 2 returning\n");
    pthread_exit((void*)200);
}

void *thrd_func3(){
    while (1)
    {
        //printf("thread 3: I`m going to die in 3 seconds\n");   //注释循环体内，就没有取消点了，于是cancel不起作用了
        //sleep(1);
    }
    pthread_exit((void*)666);
}

int main(){
    pthread_t tid;
    void * ret;

    pthread_create(&tid, NULL, thrd_func1, NULL);
    pthread_join(tid, &ret);
    printf("thread 1 exit code = %ld\n\n", (long)ret);

    pthread_create(&tid, NULL, thrd_func2, NULL);
    pthread_join(tid, &ret);
    printf("thread 2 exit code = %ld\n\n", (long)ret);

    pthread_create(&tid, NULL, thrd_func3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &ret);
    printf("thread 3 exit code = %ld\n\n", (long)ret);

    
}