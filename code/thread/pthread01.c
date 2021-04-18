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



void printids(const char*s){
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %d tid %lu\n", s, pid, tid);

}

void *thr_fn(void *arg){
    printids("new thread: ");
    return ((void *) 0);
}

int main() {
    pthread_t ntid;
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        ERR_EXIT("creat error");
    printids("main thread:");
    sleep(1);
    exit(0);
    return 0;
}