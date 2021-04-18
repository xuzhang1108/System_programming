#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void * thrd_func(){
    printf("In thread: thread id = %lu, pid = %d\n", pthread_self(), getpid());
    pthread_exit((void*)1);
}

int main(){
    pthread_t tid;
    int ret;
    int* retval;

    ret = pthread_create(&tid, NULL, thrd_func, NULL);
    if(ret != 0){
        fprintf(stderr, "create error %s\n", strerror(ret));
        exit(1);
    }

    ret = pthread_join(tid, (void**)&retval);
    if(ret != 0){
        fprintf(stderr, "create error %s\n", strerror(ret));
        exit(1);
    }
    printf("thread exit with code %d\n", retval);
    pthread_exit((void*)2);
}