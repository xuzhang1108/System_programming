#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

#define ERR_EXIT(m)\
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while (0)

void *thr_fn1(){
    printf("thread 1 returning\n");
    return ((void*) 1);
}

void *thr_fn2(){
    printf("thread 2 exiting\n");
    pthread_exit((void*) 2);
}

int main(){
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if(err != 0){
        ERR_EXIT("can`t create thread 1");
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if(err != 0)
        ERR_EXIT("can`t create thread 2");
    
    err = pthread_join(tid1, &tret);
    if(err != 0)
        ERR_EXIT("can`t join with thread 1");

    printf("thread 1 exit code %ld\n", (long)tret);
    err = pthread_join(tid2, &tret);
    if(err != 0)
        ERR_EXIT("can`t join with thread 2");
    printf("thread 2 exit code %ld\n", (long)tret);
    exit(0);

}

