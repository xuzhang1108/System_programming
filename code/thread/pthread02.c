#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * thrd_func(){
	printf("In thread: new thead = %lu, pid = %u\n", pthread_self(), getpid());
	return ((void*)0);
}


int main(){
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid, NULL, thrd_func, NULL);
	if (ret != 0){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}
	sleep(1);
	printf("In main: main thread = %lu, pid = %u\n", pthread_self(), getpid());
	exit(1);
}

