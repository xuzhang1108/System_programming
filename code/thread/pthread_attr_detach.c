#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * thrd_func(){
	return ((void*)0);
}


int main(){
	pthread_t tid;
	int ret;
    pthread_attr_t attr;

    ret = pthread_attr_init(&attr);
    if (ret != 0){
		fprintf(stderr, "pthread_init error: %s\n", strerror(ret));
		exit(1);
	}

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	ret = pthread_create(&tid, &attr, thrd_func, NULL);
	if (ret != 0){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}
	ret = pthread_join(tid, NULL);
    if (ret != 0){
		fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
		exit(1);
	}
	printf("------------------------- join ret = %d\n", ret);
	exit(1);
}

