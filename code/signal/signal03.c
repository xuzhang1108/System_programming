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
}

int main() {
    if (signal(SIGUSR1, handler) == SIG_ERR)
        ERR_EXIT("signal error");

    pid_t pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");

    if (pid == 0) {
        /* pid = getpgrp();
        kill(-pid, SIGUSR1); */
        killpg(getpgrp(), SIGUSR1);
        exit(EXIT_SUCCESS);
    }

    int n = 5;
    do {
        n = sleep(n);
    } while (n > 0);
  
    
    return 0;
}