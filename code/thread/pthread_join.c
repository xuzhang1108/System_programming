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

typedef struct {
    char ch;
    int var;
    char str[64];
} exit_t;


void * thrd_func(){
    exit_t *retvar = (exit_t *) malloc(sizeof(exit_t));

    retvar->ch = 'm';
    retvar->var = 200;
    strcpy(retvar->str, "my thread\n");

	pthread_exit((void*)retvar);
}


int main(){
	pthread_t tid;
	int ret;
    exit_t* retval;

    printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());

	ret = pthread_create(&tid, NULL, thrd_func, NULL);
	if (ret != 0){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}
	
    pthread_join(tid, (void**)&retval);
	printf("thread exit ch = %c, var = %d, str = %s\n", retval->ch, retval->var, retval->str);
	pthread_exit((void *)1);
}
