#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int counter = 0;
pthread_rwlock_t rwlcok ;

void* th_write(void*arg){
    int t;
    int i = (int)arg;

    while (1)
    {
        t = counter;
        usleep(1000);

        pthread_rwlock_wrlock(&rwlcok);
        printf("===============================write %d: %lu: counter = %d ++counter = %d\n", i, pthread_self(), t, ++counter);
        pthread_rwlock_unlock(&rwlcok);

        usleep(5000);
    }
    return NULL;
}

void* th_read(void*arg){
    int i = (int)arg;

    while (1)
    {
        pthread_rwlock_rdlock(&rwlcok);
        printf("------------------------------read %d: %lu: %d\n", i, pthread_self(), counter);
        pthread_rwlock_unlock(&rwlcok);
        usleep(900);
    }
    
}

int main(){
    int i;
    pthread_t tid[8];

    pthread_rwlock_init(&rwlcok, NULL);
    for(i = 0; i < 3; i++){
        pthread_create(&tid[i], NULL, th_write, (void*)i);
    }

    for(i = 0; i < 5; i++){
        pthread_create(&tid[i+3], NULL, th_read, (void*)i);
    }

    for(i = 0; i < 8; i++){
        pthread_join(tid[i], NULL);
    }
    pthread_rwlock_destroy(&rwlcok);
    return 0;
}