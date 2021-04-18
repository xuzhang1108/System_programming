#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *thrd_func( ){
    int n = 3;

    while (n--)
    {
        printf("thread count %d\n", n);
        sleep(1);
    }
    return ((void*)1);
}

int main() {
    pthread_t tid;
    void *retval;
    int err;

    pthread_create(&tid, NULL, thrd_func, NULL);
    //pthread_detach(tid);   //让线程分离   自动退出，无系统残留资源

    while (1)
    {
        err = pthread_join(tid, &retval);
        printf("-------------------- err = %d\n", err);

        if(err != 0)
            fprintf(stderr, "thread_join error: %s\n", strerror(err));
        else
            fprintf(stderr, "thread exit code %ld\n", (long)retval);

        sleep(1);
    }

}