#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct msg
{
    int val;
    struct msg* next;
};

struct msg* head = NULL;
struct msg* mp = NULL;


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void* producter(void * arg){
    while (1)
    {
         //product node
        mp = malloc(sizeof(struct msg));
        mp->val= rand() % 400 + 1;   // val = from 1 to 400
        printf("------producted------%d\n", mp->val); 

        //add share space, firstlu adding lock
        pthread_mutex_lock(&mutex);
        mp->next = head;
        head = mp;
        pthread_mutex_unlock(&mutex);
        
        pthread_cond_signal(&cond);
        sleep(rand() % 5);
    }
    return NULL;
}

void* consumer(void * arg){
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while(head == NULL){
            pthread_cond_wait(&cond, &mutex);
        }
        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&mutex);

        printf("----Consume-----%d\n", mp->val);
        free(mp);
        mp = NULL;
        sleep(rand()%5);
    }
    return NULL;
}

int main(){
    pthread_t ptid, ctid;
    int ret;
    srand(time(NULL));

    ret = pthread_create(&ptid, NULL, producter, NULL);
    if(ret != 0){
        fprintf(stderr, "create error: %s\n", strerror(ret));
        exit(1);
    }

    ret = pthread_create(&ctid, NULL, consumer, NULL);
    if(ret != 0){
        fprintf(stderr, "create error: %s\n", strerror(ret));
        exit(1);
    }

    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);
    return 0;
}