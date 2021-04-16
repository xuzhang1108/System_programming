#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#define ERR_EXIT(m)\
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while (0)

void handler(int sig) {
    printf("recv a sig = %d\n", sig);
    sleep(1);
}

int main() {
    if (signal(SIGINT, handler) == SIG_ERR)
        ERR_EXIT("signal error");

    for (;;) {
        pause();
        printf("pause return \n");
    }
    
    return 0;
}