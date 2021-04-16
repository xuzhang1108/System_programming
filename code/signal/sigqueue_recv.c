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

void handler(int sig, siginfo_t *info, void *ctx) {
    printf("recv a sig %d data = %d\n", sig, info->si_value.sival_int);
} 

int main() {
    struct sigaction act;
    act.sa_sigaction = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGINT, &act, NULL) < 0)
        ERR_EXIT("sigaction error");

    for (;;) ;
        //pause();
       
    return 0;
}
